# RemoteProcedureCall

Projet C d'exécution de commandes sur un serveur à partir de commandes envoyées par un client.

## Description

    - Split.x

Ce fichier spécifie les structures et les fonctions partagées par le client et le serveur, ce qui permet au client et au serveur de savoir à quoi s'attendre venant de l'autre.
Les fonctions ne peuvent prendre te renvoyer qu'un seul argument, d'où l'utilisation extensive de structures.

    - Serveur:

Lancé via l'invite de commandes, il se met en attente de clients.
Sa seule fonction est d'exécuter des fonctions que les clients vont appeler, de leur renvoyer un résultat et d'afficher l'exécution réalisée.

    - Client:

Lancé via l'invite de commandes, il se connecte au serveur via l'adresse IP et le port spécifié.
Ici, les fonctions appelées sont codées en dur et les résultats sont affichés pour suivre le bon déroulement des appels.
