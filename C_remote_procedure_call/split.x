struct abonnement {
  int id;
  char nom[40];
  int prix;
};

struct utilisateur {
  int id;
  char nom[40];
  char email[40];
  char adresse[40];
  char motdepasse[40];
  abonnement liste_abo[10];
  int nb_abo;
};


struct offre {
  int id;
  abonnement abo;
  float prix_partage;
};

struct evaluation {
  int id;
  utilisateur user;
  int note;
  char commentaire[255];
};


struct gestion_abonnement {
	utilisateur user;
	abonnement abo;
};


struct partage_abonnement {
	utilisateur user;
	offre partage;
	int co_abonnes[10];
};

struct select_partage {
	utilisateur user;
	partage_abonnement selectionne;
};

struct search {
	char nom[40];
	int prix_max;
};

struct note {
	int id;
	utilisateur user;
	evaluation eval;
};



program  SPLITPROG{
	version SPLITVERS{
	
		int INSCRIPTION(utilisateur u)=1;
		int DESINSCRIPTION(utilisateur u)=2;
		utilisateur ADD_ABONNEMENT(gestion_abonnement add_abo)=3;
		utilisateur REMOVE_ABONNEMENT(gestion_abonnement delete_abo)=4;
		int PROPOSE_PARTAGE_ABONNEMENT(partage_abonnement propose)=5;
		int CANCEL_PARTAGE_ABONNEMENT(partage_abonnement cancel)=6;
		partage_abonnement SEARCH_PARTAGE_ABONNEMENT(search recherche)=7;
		int SELECT_PARTAGE_ABONNEMENT(select_partage select)=8;
		int CANCEL_CO_ABONNEMENT(select_partage cancel)=9;
		int ADD_EVALUATION(note n)=10;
		int CONNECT_UTILISATEUR(utilisateur u)=11;
		utilisateur UPDATE_UTILISATEUR(utilisateur u)=12;
		
	}=1;
}=0x23456789;
