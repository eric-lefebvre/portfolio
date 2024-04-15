import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.List;

public class ServeurTCP {
    private ServerSocket serverSocket;
    private List<ClientHandler> clients;
    private List<String> ListMessages;

    public ServeurTCP(int port) {
        try {
            serverSocket = new ServerSocket(port);
            clients = new ArrayList<>();
            ListMessages = new ArrayList<>();
            System.out.println("Serveur lance, en attente de connexions...");

            while (true) {
                Socket clientSocket = serverSocket.accept();
                //un client s'ets connecte
                System.out.println("Client connecte: " + clientSocket);
                //on fais un thread avec le nouveau client connecte 
                ClientHandler clientHandler = new ClientHandler(clientSocket);
                //on ajoute ce client dans une liste de threadClient pour memoriser tous les clients connectes
                clients.add(clientHandler);
                //onlance le thread
                clientHandler.start();
            }
        } catch (IOException e) {
            System.err.println("Impossible d'accepter la connexion, fermeture du serveur, erreur: " + e.getMessage());
        } finally {
            try {
                serverSocket.close();
            } catch (IOException e) {
                System.err.println("Fermeture du socket serveur impossible: " + e.getMessage());
            }
        }
    }

    private class ClientHandler extends Thread {
        private Socket clientSocket;
        private ObjectOutputStream output;
        private ObjectInputStream input;

        public ClientHandler(Socket socket) {
            this.clientSocket = socket;
            try {
            	output = new ObjectOutputStream(clientSocket.getOutputStream());
            	input = new ObjectInputStream(clientSocket.getInputStream());
            } catch (IOException e) {
                System.err.println("Creation des streams impossible: " + e.getMessage());
            }
        }

        public void run() {
            try {
                byte[] buffer = new byte[100];
                int bytesRead;
                
                while ((bytesRead = input.read(buffer)) == -1);
                System.out.println("Client pret");
                
                //envoi au client de l'historique des messages
                for (String message : ListMessages) {
            		byte[] outbuffer = message.getBytes();
                    output.write(outbuffer);
                    output.flush();
                    System.out.println("Message envoye a " + clientSocket + " : " + message);
                }
                
                //tant qu'il y a des choses a lire 
                while ((bytesRead = input.read(buffer)) != -1) {
                	//on fait un message avec ce qu'on a lu 
                    String message = new String(buffer, 0, bytesRead);
                    System.out.println("Message recu du client " + clientSocket + ": " + message);
                    ListMessages.add(message);

                    // envoie du message que le serveur vient de recevoir a  tous les clients excepte le client qui a envoye ce message
                    for (ClientHandler client : clients) {
                    	//on teste si le client de la liste est celui qui a envoye le message qui vient d'etre recu
                		byte[] outbuffer = message.getBytes();
                        client.output.write(outbuffer);
                        client.output.flush();
                        System.out.println("Message envoye a tous les clients : " + message);
                    	
                    }
                }
            } catch (IOException e) {
                System.err.println("Problème de communication avec le client, fermeture de la connexion, erreur: " + e.getMessage());
            } finally {
                try {
                    if (input != null) input.close();
                    if (output != null) output.close();
                    clientSocket.close();

                    // Retirer le client de la liste des clients connectes
                    clients.remove(this);
                    System.out.println("Client deconnecte: " + clientSocket);
                    
                } catch (IOException e) {
                    System.err.println("Fermeture de la socket client " + clientSocket + " impossible: " + e.getMessage());
                }
            }
        }
    }
    
    private void pause(int duree) {
		try {
			Thread.sleep(duree);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

    public static void main(String[] args) {
        if(args.length != 1) {
        	System.out.println("Usage : ServeurTCP <port>");
        	return;
        }
        new ServeurTCP(Integer.parseInt(args[0]));
    }
}

