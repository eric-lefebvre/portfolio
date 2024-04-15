import java.io.*;
import java.net.*;
import java.util.*;

import Exception.ConnexionException;

public class ClientTCP {
    private Socket socket;
    private ObjectOutputStream output;
    private ObjectInputStream input;
    private List<MessageListener> messageListeners = new ArrayList<>();
    private boolean running;
    private List<ErrorListener> errorListeners = new ArrayList<>();

    public ClientTCP(String serverAddress, int serverPort) throws ConnexionException {
        try {
            // Creation de la socket et des flux
            socket = new Socket(serverAddress, serverPort);
            output = new ObjectOutputStream(socket.getOutputStream());
            input = new ObjectInputStream(socket.getInputStream());

            // Demarrage d'un thread pour lire les reponses du serveur
            Thread responseThread = new Thread(new ResponseHandler());
            running = true;
            responseThread.start();

        } catch (IOException e) {
            System.err.println("Impossible de se connecter au serveur, erreur: " + e.getMessage());
            throw new ConnexionException("Erreur connexion");
        }
    }
    
    public void Deconnexion() {
    	try {
    		running = false;
            // Fermer les flux de sortie et d'entree
            if (output != null) {
                output.close();
            }
            if (input != null) {
                input.close();
            }
            
            // Fermer la socket
            if (socket != null && !socket.isClosed()) {
                socket.close();
            }
            
            System.out.println("Deconnexion reussie.");
        } catch (IOException e) {
            System.err.println("Erreur lors de la déconnexion : " + e.getMessage());
        }
    }

    // Methode pour envoyer un message au serveur
    public void SendMessage(String message) {
        try {
            byte[] buffer = message.getBytes();
            output.write(buffer);
            output.flush();
            System.out.println("Message envoye: " + message);
        } catch (IOException e) {
            System.err.println("Erreur dans l'envoi du message: " + e.getMessage());
        }
    }

    // Ajouter un ecouteur pour les messages
    public void addMessageListener(MessageListener listener) {
        messageListeners.add(listener);
    }
    // Ajouter un ecouteur pour les erreurs
    public void addErrorListener(ErrorListener listener) {
        errorListeners.add(listener);
    }

    // Methode pour notifier les ecouteurs qu'un message a ete recu
    private void notifyMessageReceived(String message) {
        for (MessageListener listener : messageListeners) {
            listener.messageReceived(message);
            
        }
    }
    // Methode pour notifier les ecouteurs qu'une erreur a ete recu
    private void notifyErrorReceived(String message) {
        for (ErrorListener listener : errorListeners) {
            listener.errorReceived(message);
            
        }
    }
    

    // Classe interne pour gerer la reception des messages du serveur dans un thread separe
    private class ResponseHandler implements Runnable {
        @Override
        public void run() {
            try {
                while (running) {
                    byte[] responseBuffer = new byte[100];
                    int bytesRead = input.read(responseBuffer);
                    
                    if (bytesRead == -1) {
                        // Si bytesRead est -1, la connexion a été fermee par le serveur
                        System.out.println("Connexion au serveur fermee.");
                        break;
                    }
                    
                    String response = new String(responseBuffer, 0, bytesRead);
                    System.out.println("Message recu: " + response);

                    // Notifier les ecouteurs qu'un message a ete recu
                    notifyMessageReceived(response);
                }
            } catch (IOException e) {
                if (!socket.isClosed()) {
                    // Si la connexion n'est pas fermee, erreur reelle
                    System.err.println("Erreur lors de la lecture de la reponse: " + e.getMessage());
                    notifyErrorReceived("error");
                    pause(1000);
                    Deconnexion();
                }
            }
        }
    }
    
    private void pause(int x) {
    	try {
    		Thread.sleep(x);
    	}catch(InterruptedException e) {
    		e.printStackTrace();
    	}
    }

    // Interface pour les ecouteurs de messages
    public interface MessageListener {
        void messageReceived(String message);
    }
    // Interface pour les ecouteurs de messages d'erreur du serveur
    public interface ErrorListener {
        void errorReceived(String message);
    }
}
