#include <stdio.h>
#include "header.h"
#include <time.h>
#include <string.h>

extern int nombre_reclamation;
extern int nombre_utilisateur;
utilisateur* trouver_utilisateur(char email[TAILLE_EMAIL])
{
    int i;
    for(i = 0; i < nombre_utilisateur; i++)
    {
        if(strcmp(email, tableau_utilisateur[i].email) == 0)
            return(&(tableau_utilisateur[i]));
    }
    return(NULL);
}
char date_de_reclamation()
{
    int time_t, date_reclamation;
    date_reclamation = time(NULL);
    return(date_reclamation);
}

int generation_ID_reclamation()
{
    int count = 0;
    return(count++);
}
