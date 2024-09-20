#include"header.h"
#include<stdio.h>

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