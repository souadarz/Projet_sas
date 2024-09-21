#include <stdio.h>
#include "header.h"

utilisateur* trouver_utilisateur(char email[TAILLE_EMAIL])
{
    int i;
    for(i = 0; i <= nombre_utilisateur; i++)
    {
        if(strcmp(email, tableau_utilisateur[i].email) == 0)
            return(&(tableau_utilisateur[i]));
    }
    return(NULL);
}