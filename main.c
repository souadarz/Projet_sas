#include<stdio.h>

#define TAILLE 100
#define TAILLE_CLIENT 50
#define TAILLE_ID 4
#define TAILLE_MOTIF 100
#define TAILLE_CATEGORIE 100
#define TAILLE_STATUS 50
#define TAILLE_DATE 10

typedef struct reclamation {
    char client;
    int ID;
    char motif;
    char description;
    char categorie;
    char status;
    char date;
} reclamation;

reclamation tableau_reclamation[TAILLE];
void ajouter_reclamation();
void afficher_reclamation();
void modifier_reclamation();
void supprimer_reclamation();
void traiter_reclamation();
void rechercher_reclamation();

void menu()
{
    int n; 
    do{
        printf("1. ajouter une réclamation");
        printf("2. afficher la liste des réclamations");
        printf("3. modifier une réclamation");
        printf("4. supprimer  une réclamation");
        printf("5. traiter une réclamation");
        printf("6. rechercher une  réclamation");
        printf("7. quitter");
    }while(n != 7);
    switch(n){
        case 1: ajouter_reclamation(); break;
        case 2: afficher_reclamation(); break;
        case 3: modifier_reclamation(); break;
        case 4: supprimer_reclamation(); break;
        case 5: traiter_reclamation(); break;
        case 6: rechercher_reclamation(); break;
        default: printf("entrer un nombre se trouve dans la liste");
    }
}
int main()
{
    menu();
}