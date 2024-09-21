#include "header.h"
#include<stdio.h>
#include<string.h>

int validation_motdepass(char motdepass[TAILLE_MOTDEPASS], char nom_utilisateur[TAILLE_NOM])
{
    int i, miniscule_found = 0, majuscule_found = 0, chiffre_found = 0, caractere_found = 0;
    if(strlen(motdepass) < 8)
        return(0);
    if(strstr(motdepass, nom_utilisateur) != NULL)
        return(-1);
    for(i = 0; motdepass[i] != '\0'; i++)
    {
        if(motdepass[i] >='a' && motdepass[i] <= 'z')
            miniscule_found = 1;
        else if(motdepass[i] >= 'A' && motdepass[i] <= 'Z')
            majuscule_found = 1;
        else if(motdepass[i] >= '0' && motdepass[i] <= '9')
            chiffre_found = 1;
        else if(motdepass[i] >= 33 && motdepass[i] <= 47 || motdepass[i] == '@')
            caractere_found = 1;
    }
    if(miniscule_found && majuscule_found && chiffre_found && caractere_found)
        return(1);
    return(0);
}