#include <stdio.h>
#include "header.h"
#include <string.h>

extern int nombre_reclamation;
extern int nombre_utilisateur;
utilisateur trouver_utilisateur(char email[TAILLE_EMAIL])
{
    int i;
    for(i = 0; i < nombre_utilisateur; i++)
    {
        if(strcmp(email, tableau_utilisateur[i].email) == 0)
            return (tableau_utilisateur[i]);
    }
    utilisateur empty_user = {0}; 
    return empty_user;
}

int generation_ID_reclamation()
{
    int count = 0;
    return(count++);
}
