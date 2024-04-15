/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "split.h"
#define SIZE_MAX 10
#define NB_ELEMENTS(array) (sizeof(array) / sizeof(array[0]))



utilisateur all_utilisateur[SIZE_MAX];

partage_abonnement all_partage[SIZE_MAX];

note all_notes[SIZE_MAX];

int utilisateur_connecte;

gestion_abonnement hashmap_abonnement[SIZE_MAX];

int get_nb_utilisateur(void) {
	int nb_utilisateurs = 0;
	for (; all_utilisateur[nb_utilisateurs].id != 0; nb_utilisateurs++);
	return nb_utilisateurs;
}

int *
inscription_1_svc(utilisateur *argp, struct svc_req *rqstp)
{
	static int  result = 0;
	printf("\n******************SERVEUR INSCRIPTION***********************\n");

	int nb_utilisateurs = get_nb_utilisateur();
	
	
	if(nb_utilisateurs < SIZE_MAX){
		all_utilisateur[nb_utilisateurs]=*argp;
		all_utilisateur[nb_utilisateurs].id = nb_utilisateurs + 1;
		utilisateur u = all_utilisateur[nb_utilisateurs];
		printf("Nouvelle inscription\n");
		printf("Id : %d, Nom : %s, Email : %s, Adresse : %s \n", u.id, u.nom, u.email, u.adresse);
		result = u.id; 
	}
	else {
		printf("Inscription refusée, il n'y a plus de place.\n");
		result = -1;
	}
	return &result;

}

int *
desinscription_1_svc(utilisateur *argp, struct svc_req *rqstp)
{
	static int  result = -1;
	printf("\n******************SERVEUR DESINSCRIPTION***********************\n");

	int nb_utilisateurs = get_nb_utilisateur();

	utilisateur all_utilisateur2[SIZE_MAX];
	
	int j = 0;

	for(int i = 0; i<nb_utilisateurs; i++){
		if(all_utilisateur[i].id != argp->id){
			all_utilisateur2[j++] = all_utilisateur[i];
		}
		if(all_utilisateur[i].id == argp->id){
			result = 0;
			
		}
	}
	if(result == 0){
		for (int i = 0; i < nb_utilisateurs; i++) {
	    	all_utilisateur[i] = all_utilisateur2[i];
	  	}
	  	printf("Désinscription réussie.\n");
	  	printf("Voici la nouvelle liste d'utilisateur :\n");
	  	
	  	int nb_utilisateurs2 = 0;
		for (; all_utilisateur2[nb_utilisateurs2].id != 0; nb_utilisateurs2++);
		
		
		
		
		if(nb_utilisateurs2 == 0){
			printf("Aucun utilisateur\n");
		}
		else {
	  		for(int i = 0; i<nb_utilisateurs2; i++){
	  			printf("Nom : %s\n", all_utilisateur[i].nom);
	  		}
	  	}
	}
	
	
	

	return &result;

}

utilisateur *
add_abonnement_1_svc(gestion_abonnement *argp, struct svc_req *rqstp)
{
	static utilisateur result;
	printf("\n******************SERVEUR ADD ABONNEMENT***********************\n");
	
	int nb_utilisateurs = get_nb_utilisateur();
	
	
	int nb_abo = argp->user.nb_abo;
	
	
	if(nb_abo < 10){
	
		//mise à jour de l'utilisateur dans le tableau all_utilisateur
		for(int j = 0; j < nb_utilisateurs; j++){
			if(all_utilisateur[j].id == argp->user.id){
				//un abonnement en plus
				//on met l'abonnement passé en param dans la liste des abonnements de l'utilisateur
				all_utilisateur[j].liste_abo[all_utilisateur[j].nb_abo] = argp->abo;
				//on place l'utilisateur mis à jour dans le result de retour
				all_utilisateur[j].nb_abo++;
				result = all_utilisateur[j];
				
			}
		}
		
		

	}
	else{
		printf("Nombre max d'abonnements atteint.\n");
		result = argp->user;
	}
	
	if(result.nb_abo != nb_abo){
		printf("Voici la nouvelle liste d'abonnements de l'utilisateur %s\n", argp->user.nom);
		for(int i = 0; i<result.nb_abo ; i++){
			printf("Abonnement d'identifiant %d à la plateforme %s au prix de %d €.\n", result.liste_abo[i].id, 
			result.liste_abo[i].nom, result.liste_abo[i].prix);
			
		}
	}
	

	return &result;


}

utilisateur *
remove_abonnement_1_svc(gestion_abonnement *argp, struct svc_req *rqstp)
{
	static utilisateur  result;
	
	printf("\n******************SERVEUR REMOVE ABONNEMENT***********************\n");
	
	int nb_utilisateurs = get_nb_utilisateur();
	
	for(int i = 0; i < nb_utilisateurs; i++){
		if(all_utilisateur[i].id == argp->user.id){
			result = all_utilisateur[i];
		}
	}
	
	int old_abo = result.nb_abo;
	
	
	
	abonnement abo = argp->abo;
	abonnement new_liste[SIZE_MAX];
	
	
	
	int j = 0;
	int change = 0;
	
	
	
	for(int i = 0; i < old_abo; i++){
		if(strcmp(result.liste_abo[i].nom, abo.nom)!=0){
			new_liste[j++] = result.liste_abo[i];
		}
		else{
			result.nb_abo--;
			change = 1;
		}
	}
	
	if(change == 1){
		for(int i = 0; i < result.nb_abo ; i++){
			result.liste_abo[i] = new_liste[i];
		}
		printf("Suppréssion de l'abonnement réussie.\n");
		printf("Voici la nouvelle liste d'abonnements de l'utilisateur %s\n", argp->user.nom);
		for(int i = 0; i<result.nb_abo ; i++){
			printf("Abonnement d'identifiant %d à la plateforme %s au prix de %d €.\n", result.liste_abo[i].id, 
			result.liste_abo[i].nom, result.liste_abo[i].prix);
			
		}
	}
	else{
		printf("L'abonnement n'a pas été trouvé dans vos abonnements actifs, aucune suppréssion.\n");
	}
	
	return &result;

}

int *
propose_partage_abonnement_1_svc(partage_abonnement *argp, struct svc_req *rqstp)
{
	static int  result = -1;
	printf("\n******************SERVEUR PROPOSE PARTAGE***********************\n");
	
	int nb_partage = 0;
	for (; all_partage[nb_partage].user.id != 0; nb_partage++);
	
	
	if(nb_partage < SIZE_MAX){
		all_partage[nb_partage] = *argp;	
		nb_partage++;
		result = 0;
	}
	
	printf("Voici la liste des partages abonnements : \n");
	for(int i = 0; i < nb_partage; i++){
		printf("Abonnement à %s partagé par %s au prix de %.2f €/pers.\n", all_partage[i].partage.abo.nom, all_partage[i].user.nom,
		all_partage[i].partage.prix_partage);
	}
	
	
	return &result;
}

int *
cancel_partage_abonnement_1_svc(partage_abonnement *argp, struct svc_req *rqstp)
{
	static int  result = -1;
	printf("\n******************SERVEUR CANCEL PARTAGE***********************\n");
	
	int j = 0;
	partage_abonnement abo_delete;
	int nb_partage = 0;
	for (; all_partage[nb_partage].partage.id != 0; nb_partage++);
	
	partage_abonnement new_liste[SIZE_MAX];
	
	for(int i = 0; i < nb_partage; i++){
		if(all_partage[i].partage.id != argp->partage.id){
			new_liste[j++] = all_partage[i];
		}
		else{
			abo_delete = all_partage[i];
			result = 0;
		}
	}
	
	if(result == 0){
		for(int i = 0; i < nb_partage - 1 ; i++){
			all_partage[i] = new_liste[i];
		}
		printf("Votre offre d'abonnement à %s (id de l'abonnement = %d) au prix de %.2f €/pers a bien été supprimé.\n",
		abo_delete.partage.abo.nom, abo_delete.partage.abo.id, abo_delete.partage.prix_partage);
	}
	else{
	printf("L'abonnement que vous voulez annulé n'existe pas dans vos offres d'abonnements\n");
	}
	
	

	
	return &result;
}

partage_abonnement *
search_partage_abonnement_1_svc(search *argp, struct svc_req *rqstp)
{
	printf("\n******************SERVEUR SEARCH PARTAGE***********************\n");
	static partage_abonnement  result;
	result.partage.prix_partage = 100000000;
	
	double find_prix = -1.00;
	int find = -1;
	
	int nb_partage = 0;
	for (; all_partage[nb_partage].partage.id != 0; nb_partage++);

	for(int i = 0; i < nb_partage; i++){
		if(strcmp(argp->nom, all_partage[i].partage.abo.nom)==0){
			if(argp->prix_max >= all_partage[i].partage.prix_partage){
				if(result.partage.prix_partage > all_partage[i].partage.prix_partage){
					result = all_partage[i];
					find =  0;
				}
			}
			else{
				find_prix = all_partage[i].partage.prix_partage;
			}
		}
	}
	
	if(find == -1 && (int)find_prix != -1){
		printf("Aucun abonnement trouvé avec vos critères mais l'abonnement que vous cherchez existe à un prix plus élevé qui est");
		printf(" de %2.f €/pers.\n", find_prix);
	}
	else if(find == -1 && (int)find_prix == -1){
		printf("Il n'existe aucun abonnement à cette plateforme, peu importe le prix.\n");
	}
	else {
		printf("Un abonnement correspondant à votre recherche a été trouvé. Il est au prix de %.2f €/pers.\n", 
		result.partage.prix_partage);
	}

	return &result;
}

int *
select_partage_abonnement_1_svc(select_partage *argp, struct svc_req *rqstp)
{
	printf("\n******************SERVEUR SELECT PARTAGE***********************\n");
	static int  result = -1;
	
	int nb_co_abo = 0;
	for (; argp->selectionne.co_abonnes[nb_co_abo] != 0; nb_co_abo++);
	
	int nb_partage = 0;
	for (; all_partage[nb_partage].partage.id != 0; nb_partage++);
	
	int position = -1;
	for(int i = 0; i < nb_partage ; i++){
		if(all_partage[i].partage.id == argp->selectionne.partage.id){
			position = i;
			break;
		}
	}

	if(nb_co_abo < SIZE_MAX){
		if(position != -1){
			all_partage[position].co_abonnes[nb_co_abo] = argp->user.id;
			printf("Votre souscription au partage d'abonnement proposé par %s à la plateforme %s à bien été pris en compte.\n", 
			argp->selectionne.user.nom, argp->selectionne.partage.abo.nom);
			result = 0;
		}
		else{
			printf("Le partage d'abonnement que vous avez selectionné n'existe pas.\n");
		}
	}
	else {
		printf("Ce partage d'abonnement est complet.\n");
	}
	
	return &result;
}

int *
cancel_co_abonnement_1_svc(select_partage *argp, struct svc_req *rqstp)
{
	printf("\n******************SERVEUR CANCEL CO-ABONNEMENT***********************\n");
	static int  result = -1;

	utilisateur coabonne;
	partage_abonnement *partage_cancel;
	int new_liste_coabonne[10];
	
	for (int i = 0; i < get_nb_utilisateur(); i++) {
		if (all_utilisateur[i].id == argp->user.id)
			coabonne = all_utilisateur[i];
	}
	
	if (coabonne.id == 0) {
		printf("Utilisateur introuvable, annulation du co-abbonnement impossible\n");
		return &result;
	}
	
	for (int i = 0; i < SIZE_MAX; i++) {
		if (all_partage[i].partage.id == argp->selectionne.partage.id) {
			partage_cancel = &all_partage[i];
		}
	}
	
	if (partage_cancel->partage.id == 0) {
		printf("Partage introuvable, annulation du co-abbonnement impossible\n");
		return &result;
	}
	
	for (int i = 0, j = 0; i < 10; i++, j++) {
		if (partage_cancel->co_abonnes[i] == coabonne.id) {
			j--;
			continue;
		}
		new_liste_coabonne[j] = partage_cancel->co_abonnes[i];
	}
	
	for (int i = 0; i < 10; i++)
		partage_cancel->co_abonnes[i] = new_liste_coabonne[i];
	
	printf("Annulation du co-abonnement reussi\n");
	printf("Voici la nouvelle liste de co-abonnés:\n");
	int nb_coabonnes = 0;
	for (; partage_cancel->co_abonnes[nb_coabonnes] != 0; nb_coabonnes++) {
		for (int j = 0; all_utilisateur[j].id != 0; j++)
			if (all_utilisateur[j].id == partage_cancel->co_abonnes[nb_coabonnes])
				printf("Utilisateur: %s\n", all_utilisateur[j].nom);
	}
	if (nb_coabonnes == 0)
		printf("Aucun co-abonne\n");
	result = 0;
	return &result;

}

int *
add_evaluation_1_svc(note *argp, struct svc_req *rqstp)
{
	printf("\n******************SERVEUR ADD EVALUATION***********************\n");
	static int  result = -1;

	utilisateur evalue;
	utilisateur evaluateur;
	
	for (int i = 0; i < get_nb_utilisateur(); i++) {
		if (all_utilisateur[i].id == argp->user.id)
			evalue = all_utilisateur[i];
		if (all_utilisateur[i].id == argp->eval.user.id)
			evaluateur = all_utilisateur[i];
	}
	
	if (evaluateur.id == 0 || evalue.id == 0) {
		printf("Utilisateur introuvable, note non aoutée\n");
		return &result;
	}
	
	int nb_notes = 0;
	for (; all_notes[nb_notes].id != 0; nb_notes++);
	if (nb_notes >= SIZE_MAX) {
		printf("Nombre de notes maximal atteint\n");
		return &result;
	}
	
	all_notes[nb_notes] = *argp;
	
	printf("Ajout de la note réussi\n");
	printf("Evalue: %s, Note: %d, Evaluateur: %s\n", 
		all_notes[nb_notes].user.nom, all_notes[nb_notes].eval.note, all_notes[nb_notes].eval.user.nom);
	result = 0;
	return &result;


}


int *
connect_utilisateur_1_svc(utilisateur *argp, struct svc_req *rqstp)
{
	printf("\n******************SERVEUR CONNEXION***********************\n");
	static int  result;

	for (int i = 0; i < get_nb_utilisateur(); i++) {
		if (all_utilisateur[i].id == argp->id) {
			utilisateur_connecte = argp->id;
			printf("Connexion réussie: id de l'utilisateur connecte: %d\n", utilisateur_connecte);
			result = utilisateur_connecte;
			return &result;
		}
	}
	
	printf("Connexion impossible, utilisateur introuvable\n");
	result = -1;
	return &result;

}

utilisateur *
update_utilisateur_1_svc(utilisateur *argp, struct svc_req *rqstp)
{
	printf("\n******************SERVEUR UPDATE UTILISATEUR***********************\n");
	
	static utilisateur  result;
	
	
	result.id = 0;
	int find = -1;

	for(int i = 0; i < get_nb_utilisateur(); i++){
		if(all_utilisateur[i].id == utilisateur_connecte){
			result.id = utilisateur_connecte;
			strcpy(all_utilisateur[i].nom, argp->nom);
			strcpy(all_utilisateur[i].adresse, argp->adresse);
			strcpy(all_utilisateur[i].email, argp->email);
			result = all_utilisateur[i];
			
			find = 0;
		}
	}
	if(find == 0){
		printf("Le compte a bien été modifié, voici ses nouvelles informations : \n");
		printf("Nom : %s, adresse : %s, email : %s\n", argp->nom, argp->adresse, argp->email);
		
	}
	else{
		printf("Impossible de modifier\n");
	}

	return &result;
}