#ifndef HEARED_H
#define HEADER_H

#define TAILLE 100
#define TAILLE_CLIENT 50
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
    char client[TAILLE_CLIENT];
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

utilisateur tableau_utilisateur[TAILLE_UTILISATEUR];
reclamation tableau_reclamation[TAILLE];
void menu_1();
void menu_2();
void menu_3();
void ajouter_reclamation();
void afficher_reclamation();
void modifier_reclamation();
void supprimer_reclamation();
void traiter_reclamation();
void rechercher_reclamation();

int nombre_utilisateur = 0;
#endif