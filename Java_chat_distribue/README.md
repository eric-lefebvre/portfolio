# ChatDistribué

Projet Java de discussion entre plusieurs client via un serveur qui sert de relai aux messages.

## Description

    - Serveur:

Lancé via l'invite de commandes, il se met en attente de clients et ajoute à une liste ceux qui se connectent.
Lorsqu'il reçoit un message, le serveur l'envoie à tous les clients connectés.
Les erreurs de déconnexion et reconnexion sont partiellement gérées.

    - Client:

La classe client est utilisée par l'interface homme machine à l'aide de boutons.
Grâce à l'adresse IP et au numéro de port, on peut se connecter au serveur.
La fenêtre de droite de l'IHM permet d'envoyer des messages au serveur et d'en recevoir.
