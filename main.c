#include"header.h"
#include<stdio.h>
extern int nombore_reclamation;
void afficher_reclamation()
{
    
    /*int i;
    for(i = 0; i < nombore_reclamation; i++)
    {
        if(tableau_reclamation[i].)
    }*/
    printf("\nclicker entrer pour revenir en arriere");
    getchar();
    menu_reclamations();
}
void modifier_reclamation()
{
    printf("modifier");
}
void supprimer_reclamation()
{
    printf("supprimer");
}
void traiter_reclamation()
{
    printf("traiter");
}
void rechercher_reclamation()
{
    printf("rechercher");
}
void modifier_utilisateur()
{
    printf("mod utilisateur");
}
void supprimer_utilisateur()
{
    printf("sup utili");
}
void rechercher_utilisateur()
{
    printf("rech utili");
}