#include <stdio.h>
#include "header.h"
#include <string.h>
extern int id_reclamation;
extern int nombre_reclamation;
extern int nombre_utilisateur;

utilisateur* trouver_utilisateur(char email[TAILLE_EMAIL])
{
    int i;
    for(i = 0; i < nombre_utilisateur; i++)
    {
        if(strcmp(email, tableau_utilisateur[i].email) == 0)
            return (&(tableau_utilisateur[i]));
    }
    return (NULL);
}

int generation_ID_reclamation()
{
    return(id_reclamation++);
}

void rechercher_utilisateur()
{
    int i;
    char email[TAILLE_EMAIL];
    printf("\nentrer l'email de l'utilisateur a rechercher : ");
    scanf(" %[^\n]s", email);

    utilisateur* user = trouver_utilisateur(email);
    if (user != NULL)
    {
        printf("\nemail : %s", user->email);
        printf("\nmot de pass : %s", user->motdepass);
        printf("\nle nom : %s", user->nom);
        printf("\nle prenom : %s",user->prenom);
        printf("\nl'age : %d", user->age);
        printf("\nle role %d", user->role);
    }
    if (user == NULL)
        printf("aucun utilisateur trouver pour cet email");
}
void supprimer_utilisateur()
{
    int i, utilisateur_found = 0;
    char email[TAILLE_EMAIL];
    printf("\nentrer l'email de l'utilisateur a supprimer : ");
    scanf(" %[^\n]s", email);
    for (i = 0; i < nombre_utilisateur; i++)
    {
        if (strcmp(tableau_utilisateur[i].email, email) == 0)
        {
            utilisateur_found = 1;
            break;
        }
    }
    for (; i < nombre_utilisateur - 1; i++)
    {
        tableau_utilisateur[i] = tableau_utilisateur[i + 1];
    }
    if (utilisateur_found == 1)
        nombre_utilisateur--;
    else
        printf("aucun utilisateur trouver pour cet email");
}
void modifier_utilisateur()
{
    char email[TAILLE_EMAIL], nouveau_email[TAILLE_EMAIL], nouveau_motdepass[TAILLE_MOTDEPASS], 
    nouveau_nom[TAILLE_NOM], nouveau_prenom[TAILLE_PRENOM];
    int i, nouveau_role, nouveau_age;
    printf("\nentrer l'email de l'utilisateur a modifier : ");
    scanf(" %[^\n]s", email);
    printf("\nentrer le nouveau email : ");
    scanf(" %[^\n]s", nouveau_email);
    printf("\nentrer le nouveau mot de pass : ");
    scanf(" %[^\n]s", nouveau_motdepass);
    printf("\nentrer le nouveau nom : ");
    scanf(" %[^\n]s", nouveau_nom);
    printf("\nentrer le nouveau prenom : ");
    scanf(" %[^\n]s", nouveau_prenom);
    printf("\nentrer le nouveau age : ");
    scanf(" %d", &nouveau_age);
    printf("\nentrer le nouveau role : ");
    scanf(" %d", &nouveau_role);
    utilisateur* user = trouver_utilisateur(email);
    if (user != NULL)
    {
        strcpy(user->email, nouveau_email);
        strcpy(user->nom, nouveau_nom);
        strcpy(user->motdepass, nouveau_motdepass);
        strcpy(user->prenom, nouveau_prenom);
        user->age = nouveau_age;
        user->role = nouveau_role;
    }
    if (user == NULL)
        printf("aucun utilisateur trouver pour cet email");
}
