#include<stdio.h>
#include<string.h>

int validation_motdepass(char motdepass[])
{
    int i, miniscule_found = 0, majuscule_found = 0, chiffre_found = 0;
    if(strlen(motdepass) < 8)
        return(0);
    for(i = 0; motdepass[i] != '\0'; i++)
    {
        if(motdepass[i] > 'a' && motdepass[i] < 'z')
            miniscule_found = 1;
        if(miniscule_found && (motdepass[i] > 'A' && motdepass[i] < 'Z'))
            majuscule_found = 1;
        if(majuscule_found && motdepass[i] > '0' && motdepass[i] < '9')
            chiffre_found = 1;
        if(chiffre_found)
            return 1;
    }
}
int main()
{
    char motdepass[15];
    printf("entrer un mot de pass");
    scanf(" %[^\n]s", & motdepass);
    if(validation_motdepass(motdepass) == 0)
        printf("try egain");
    else
        printf("valider");
    return(0);
}