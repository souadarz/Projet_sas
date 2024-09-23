#ifndef HEARED_H
#define HEADER_H

#define TAILLE 100
#define TAILLE_MOTIF 100
#define TAILLE_DESCIPTION 1000
#define TAILLE_CATEGORIE 100
#define TAILLE_STATUS 50
#define TAILLE_DATE 10
#define TAILLE_EMAIL 50
#define TAILLE_NOM 20
#define TAILLE_PRENOM 20
#define TAILLE_MOTDEPASS 20
#define TAILLE_UTILISATEUR 100

typedef struct reclamation {
    char email[TAILLE_EMAIL];
    int ID;
    char motif[TAILLE_MOTIF];
    char description[TAILLE_DESCIPTION];
    char categorie[TAILLE_CATEGORIE];
    char status[TAILLE_STATUS];
    char date[TAILLE_DATE];
    
} reclamation;

typedef struct utilisateur {
    char email[TAILLE_EMAIL];
    char motdepass[TAILLE_MOTDEPASS];
    char nom[TAILLE_NOM];
    char prenom[TAILLE_PRENOM];
    int age;
    int role;
} utilisateur;

utilisateur* utilisateur_actuel;
utilisateur tableau_utilisateur[TAILLE_UTILISATEUR];
reclamation tableau_reclamation[TAILLE];
int validation_motdepass(char motdepass[TAILLE_MOTDEPASS], char nom_utilisateur[TAILLE_NOM]);
utilisateur* trouver_utilisateur(char email[TAILLE_EMAIL]);
void menu_reclamations();
void menu_utilisateurs();
void menu_statistiques();
void menu_admin();
void menu_agent_reclamation();
void menu_client();
void ajouter_reclamation();
void afficher_reclamation();
void modifier_reclamation();
void supprimer_reclamation();
void traiter_reclamation();
void rechercher_reclamation();
void modifier_utilisateur();
void supprimer_utilisateur();
void rechercher_utilisateur();
char date_de_reclamation();
int generation_ID_reclamation();
void initilistaion_reclamation();
#endif