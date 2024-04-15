import java.net.URL;
import java.util.ResourceBundle;

import Exception.*;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

public class ChatController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea areaDiscussion;

    @FXML
    private TextField entreeAdresseIP;

    @FXML
    private TextField entreeMessage;

    @FXML
    private TextField entreePort;

    @FXML
    private TextField entreePseudo;

    @FXML
    private Label labelEtatConnexion;
    
    ClientTCP client;
    boolean connecte;

    @FXML
    void actionBoutonConnexion(ActionEvent event) {
    	try {
    		if(!connecte) {
    			if(!entreePort.getText().isEmpty() && !entreeAdresseIP.getText().isEmpty()) {
    				areaDiscussion.setText(null);
    				client = new ClientTCP(entreeAdresseIP.getText(), Integer.parseInt(entreePort.getText()));
            		labelEtatConnexion.setText("Connecte");
            		labelEtatConnexion.setStyle("-fx-text-fill : green;");
            		
            		// Ajouter un ecouteur pour les messages
                    client.addMessageListener(new ClientMessageListener());
                    client.addErrorListener(new ClientErrorListener());
                    client.SendMessage("ready");
                    connecte = true;
    			}
    			else {
    				afficherPopupErreur("Vous devez renseigner un port et une adresse IP");
    			}
    			
    		}
    		else {
        		afficherPopupInformation("Vous etes deja connecte.");

    		}
            
    	} catch(ConnexionException e) {
    		afficherPopupInformation("Le port renseignee et/ou l'adresse IP sont invalides");
    		labelEtatConnexion.setText("Connexion echoue");
    		labelEtatConnexion.setStyle("-fx-text-fill : red;");
    	}
    }

    @FXML
    void actionBoutonDeconnexion(ActionEvent event) {
    	if(!connecte) {
    		afficherPopupInformation("Vous etes deja deconnecte");
    	}
    	else {
    		client.Deconnexion();
        	labelEtatConnexion.setText("Non connecte");
        	labelEtatConnexion.setStyle("-fx-text-fill : red;");
        	connecte = false;
    	}
    	
    }

    @FXML
    void actionBoutonEnvoyer(ActionEvent event) {
    	if(connecte) {
    		if(entreePseudo.getText().isEmpty()) {
        		afficherPopupErreur("Pseudo obligatoire pour envoyer un message");
        		return;
        	}
    		if(!entreeMessage.getText().isEmpty()) {
    			client.SendMessage(entreePseudo.getText() + " : " + entreeMessage.getText());
            	entreeMessage.setText("");
    		}
    	}
    	else {
    		afficherPopupInformation("Vous ne pouvez pas envoyer de message car vous n'etes pas connecte");
    	}
    	
    }

    @FXML
    void initialize() {
        
    }
    // Classe interne pour écouter les messages du client
    private class ClientMessageListener implements ClientTCP.MessageListener {
        @Override
        public void messageReceived(String message) {
            // Mettre à jour l'interface graphique avec le message reçu
            areaDiscussion.appendText( message + "\n");
        }
    }
 // Classe interne pour écouter les messages du client
    private class ClientErrorListener implements ClientTCP.ErrorListener {
        @Override
        public void errorReceived(String message) {
            // Mettre à jour l'interface graphique avec le message reçu
        	Platform.runLater(() -> {
        		labelEtatConnexion.setText("Connexion perdue");
            	labelEtatConnexion.setStyle("-fx-text-fill : red;");
            	connecte = false;
        	});
        	
        }
    }

    
    private void afficherPopup(String message, AlertType type) {
    	Alert alert = new Alert(type);
    	if (type == AlertType.ERROR) {
    	alert.setTitle("Erreur");
    	} else {
    	alert.setTitle("Information");
    	}
    	alert.setHeaderText(null);
    	alert.setContentText(message);
    	alert.setResizable(true);
    	alert.showAndWait();
    	
	}
	private void afficherPopupErreur(String message) {
		this.afficherPopup(message, AlertType.ERROR);
	}
	private void afficherPopupInformation(String message) {
		this.afficherPopup(message, AlertType.INFORMATION);
	}


}
