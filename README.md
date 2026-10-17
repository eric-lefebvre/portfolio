# Eric Lefebvre — Portfolio

Étudiant ingénieur à l'**ENSIM** (Le Mans Université), anciennement en licence d'informatique à l'**UBO** (Brest).
Intéressé par le jeu vidéo, la 3D et les systèmes interactifs.

---

## 🥽 [Baby Steps — jeu VR](https://github.com/eric-lefebvre/unity_vr_ensim_babysteps)

**Langage : C# (Unity)** · **Projet ENSIM — 4e année (RéaMix 2025-26)**

Jeu d'initiation à la réalité virtuelle sur Meta Quest : le joueur incarne un enfant dans une garderie transformée en centre de test, guidé par une IA. Chaque mini-jeu (lancer de balles, slot machine, Whack-a-Mole, Simon Says, Black Jack) introduit une mécanique VR de base. Architecture événementielle (observer pattern via ScriptableObjects), XR Interaction Toolkit, retours visuels, sonores et haptiques. Équipe de six étudiants.

<p>
  <img src="https://github.com/eric-lefebvre/unity_vr_ensim_babysteps/raw/main/screenshots/tableau2.png" width="49%" alt="Mini-jeu de la slot machine avec les cubes lettres">
  <img src="https://github.com/eric-lefebvre/unity_vr_ensim_babysteps/raw/main/screenshots/backroom_walls.png" width="49%" alt="Seconde salle inspirée des Backrooms">
</p>
<p align="center">
  <img src="https://github.com/eric-lefebvre/unity_vr_ensim_babysteps/raw/main/screenshots/whack_a_mole.gif" width="70%" alt="Séquence Whack-a-Mole">
</p>

---

## 🎨 [Baby Steps — modèles 3D](https://github.com/eric-lefebvre/blender_ensim_babysteps)

**Outil : Blender** · **Projet ENSIM — 4e année (RéaMix 2025-26)**

Tous les modèles 3D *low-poly* conçus pour Baby Steps : fichiers `.blend`, textures bakées et exports `.fbx` importés dans Unity (mobilier, jouets, mini-jeux, labyrinthe, animations des portes et mécanismes).

---

## 📅 [ENSIM App — emploi du temps Android](https://github.com/eric-lefebvre/android_ensim_timetable_app)

**Langage : Kotlin (Jetpack Compose)** · **Projet ENSIM**

Application Android native qui affiche l'emploi du temps à jour des étudiants de l'ENSIM à partir du flux iCal de l'université (parser ICS maison). Connexion via le CAS de l'université, recherche de salles libres avec cache partagé dans Firestore, messagerie interne en temps réel, interface bilingue FR/EN.

---

## 🫀 [Mini-golf adaptatif par biofeedback](https://github.com/eric-lefebvre/python_ensim_body_sensors)

**Langage : Python** · **Projet ENSIM — 2026**

Acquisition et traitement de signaux physiologiques (respiration, EMG, EDA, PPG, accéléromètre) via une carte BITalino pour calculer un score de stress en temps réel. Ce score est envoyé par WebSocket à un jeu de mini-golf Unity qui adapte sa difficulté (vent, tremblement de la balle, chrono).

---

## 🤖 [ChatBot Telegram](https://github.com/eric-lefebvre/api_ensim_telegram_chatbot)

**Langage : Java (Spring Boot)** · **Projet ENSIM — TP d'interopérabilité**

Bot Telegram qui agrège plusieurs API REST : météo (OpenWeatherMap), blagues (CRUD) et IA conversationnelle (Mistral AI). Expose aussi sa propre API REST (météo, blagues, envoi de messages).

---

## 🚀 [24h du Code — hackathon](https://github.com/eric-lefebvre/hackathon_24h_code)

**Langage : JavaScript (Node.js, Vite)** · **Hackathon « Les 24h du Code »**

Client pour un jeu de stratégie spatiale en ligne réalisé en 24 h : carte dynamique, leaderboard, commandes pour piloter les vaisseaux et scripts d'automatisation (récolte de ressources par les cargos, siège automatique de planètes, écoute des événements par WebSocket).

---

## 🌐 [EscapeWeb](https://github.com/eric-lefebvre/web_ubo_codeIgniter)

**Langage : PHP (CodeIgniter)** · **Projet de licence — UBO**

Jeu sérieux en ligne pour les visiteurs d'un musée d'expositions éphémères : le visiteur choisit un scénario lié à l'exposition, répond à une série de questions puis enregistre son score. Application MVC adossée à une base de données.

---

## 🖌️ [Robi — interpréteur graphique client/serveur](https://github.com/eric-lefebvre/java_ubo_client_server)

**Langage : Java** · **Projet de synthèse de L3 — UBO**

Interpréteur de scripts graphiques en S-expressions utilisable à distance : le client JavaFX envoie un script, le serveur multi-clients l'interprète, dessine le résultat en 2D et renvoie l'image. Exécution pas à pas ou en bloc, messages sérialisés en JSON (Jackson) sur socket TCP.

---

## 🎓 [GestionFormation](https://github.com/eric-lefebvre/java_ubo_management_system)

**Langage : Java** · **Projet de licence — UBO**

Système de gestion d'une formation (étudiants, unités d'enseignement, groupes) avec deux interfaces : une côté formation pour créer les UE et répartir les étudiants, une côté étudiant pour s'inscrire et choisir ses UE.

---

## 💬 [ChatDistribué](https://github.com/eric-lefebvre/java_ubo_distributed_chat)

**Langage : Java** · **Projet de licence — UBO**

Messagerie entre plusieurs clients via un serveur relais qui diffuse chaque message à tous les clients connectés. Client avec interface graphique, connexion par adresse IP et port.

---

## 🔌 [RemoteProcedureCall](https://github.com/eric-lefebvre/c_ubo_remote_procedure_call)

**Langage : C (Sun RPC)** · **Projet de licence — UBO**

Exécution de fonctions sur un serveur distant à partir d'appels envoyés par un client. Interface commune définie dans un fichier `.x` (rpcgen), échanges via des structures sérialisées en XDR.