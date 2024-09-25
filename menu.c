#include "header.h"
#include <stdio.h>

void menu_admin()
{ 
    int n;
    printf("\n1.gestion des reclamations");
    printf("\n2.gestion des utilisateurs");
    printf("\n3.generation des statistiques");
    printf("\nchoisir une option : ");
    scanf("%d", &n);
    switch(n)
    { 
        case 1: menu_reclamations(); break;
        case 2: menu_utilisateurs(); break;
        case 3: menu_statistiques(); break;
        default: printf("\nentrer un nombre se trouve dans la liste");
            menu_admin();
            break;
    }
}
void menu_reclamations()
{
    int n;
    printf("\n0. revenir");
    printf("\n1. afficher la liste des réclamations");
    printf("\n2. modifier une réclamation");
    printf("\n3. supprimer  une réclamation");
    printf("\n4. traiter une reclamation");
    printf("\n5. rechercher une reclamation");
    printf("\n6. ajouter une reclamation");
    printf("\n7. quitter");
    printf("\nentrer un nombre : ");
    scanf("%d", &n);
    getchar();
    switch(n)
    {
        case 0: menu_admin(); break;
        case 1: afficher_reclamation(); break;
        case 2: modifier_reclamation(); break;
        case 3: supprimer_reclamation(); break;
        case 4: traiter_reclamation(); break;
        case 5: rechercher_reclamation(); break;
        case 6: ajouter_reclamation(); break;
        case 7: break;
        default: printf("\nentrer un nombre se trouve dans la liste");
            break;
    }
}
void menu_utilisateurs()
{
    int n;
    printf("\n1.modifier les informations d'un utilisateur");
    printf("\n2.supprimer un utilisateur");
    printf("\n3.rechercher un utilisateur");
    printf("\nchoisir un nombre : ");
    scanf("%d", &n);
    switch (n)
    {
        case 0: menu_admin(); break;
        case 1: modifier_utilisateur(); break;
        case 2: supprimer_utilisateur(); break;
        case 3: rechercher_utilisateur(); break;
        default: printf("\nentrer un nombre se trouve dans la liste");
            break;
    }
}
void menu_statistiques()
{
    printf("statistiques");
}
void menu_agent_reclamation()
{
    printf("agent");
}

void menu_client()
{
    int n;
    printf("\n1. afficher réclamations");
    printf("\n2. modifier une réclamation");
    printf("\n3. ajouter_reclamation");
    printf("\nentrer un nombre : ");
    scanf("%d", &n);
    getchar();
    switch(n)
    {
        case 1: afficher_reclamation(); break;
        case 2: modifier_reclamation(); break;
        case 3: ajouter_reclamation(); break;
        default: printf("\nentrer un nombre se trouve dans la liste");
            break;
    }
}