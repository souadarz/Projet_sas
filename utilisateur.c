#include "header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char liste_categories[5][60] ={"categorie_1", "categorie_2", "categorie_3", "categrie_4", "categorie_5"};
int nombre_reclamation = 0;
int nombre_utilisateur = 0;
void sign_up();
void sign_in();
void sign_up_in_affichage();

void initialisation_utilisateur()
{
    // les informations du admin
    strcpy(tableau_utilisateur[0].email, "admin@gmail.com");
    strcpy(tableau_utilisateur[0].motdepass, "12ABcd@#");
    strcpy(tableau_utilisateur[0].nom, "mohamed");
    strcpy(tableau_utilisateur[0].prenom, "boclet");
    tableau_utilisateur[0].age = 35;
    tableau_utilisateur[0].role = 1;
    nombre_utilisateur++;
}

int valider_email_format(char email[TAILLE_EMAIL])
{
    int i, arobase_found = 0, point_found = 0;
    for (i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            arobase_found = 1;
        if (point_found)
            return (1);
        if (arobase_found && email[i] == '.')
            point_found = 1;
    }
    return (0);
}
int valider_email(char email[TAILLE_EMAIL])
{
    int i;
    if (valider_email_format(email) == 0)
    {
        return (-1);
    }
    for (i = 0; i < nombre_utilisateur; i++)
    {
        if (strcmp(email, tableau_utilisateur[i].email) == 0)
        {
            return (0);
        }
    }
    return (1);
}
void sign_up_in_affichage()
{
    int choix;
    do
    {
        printf("\n1. sign up");
        printf("\n2. sign in");
        printf("\nchoisir un nombre : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            sign_up();
            break;
        case 2:
            sign_in();
            break;
        default:
            printf("\nessayer de choisir un  nombre se trouvre dans la liste");
        }
    } while (((choix != 1) && (choix != 2)));
}
void sign_in()
{
    int i, nombre_essais = 0;
    char email_user[TAILLE_EMAIL], motdepass_user[TAILLE_MOTDEPASS];
    utilisateur* user;
    do
    {
        printf("\nentrer l'email : ");
        scanf(" %[^\n]s", email_user);
        printf("\nentrer le mot de pass : ");
        scanf(" %[^\n]s", motdepass_user);
        user = trouver_utilisateur(email_user);
        nombre_essais++;
        if(((user == NULL) || (strcmp(motdepass_user, user->motdepass) != 0)) && (nombre_essais < 3))
            printf("\nl'email ou le mot de pass est inccorect, essayer une autre fois");
    } while(((user == NULL) || strcmp(motdepass_user, user->motdepass) != 0) && nombre_essais < 3);

    if (user == NULL)
    {
        printf("\nessayer une autre fois dans une heure");
        sleep(10);
        sign_up_in_affichage();
    }
    else
    {
        utilisateur_actuel = user;
        switch (utilisateur_actuel->role)
        {
        case 1:
            menu_admin();
            break;
        case 2:
            menu_agent_reclamation();
            break;
        case 3:
            menu_client();
            break;
        }
    }
}

void sign_up()
{
    char email_user[TAILLE_EMAIL], motdepass_user[TAILLE_MOTDEPASS], nom_user[TAILLE_NOM], prenom_user[TAILLE_PRENOM];
    int i, age_user, test_email, test_motdepass;
    do
    {
        printf("\nentrer l'email : ");
        scanf(" %[^\n]s", email_user);
        test_email = valider_email(email_user);
        if (test_email == -1)
            printf("\nformat invalide, essayer d'entrer un email sous la forme : example@gmail.com");
        else if (test_email == 0)
            printf("\nemail deja existe, essayer avec un autre");
    } while (test_email == 0 || test_email == -1);
    printf("\nentrer le nom : ");
    scanf(" %[^\n]s", nom_user);
    printf("\nentrer le prenom : ");
    scanf(" %[^\n]s", prenom_user);
    printf("\nentrer l'age : ");
    scanf("%d", &age_user);
    do
    {
        printf("\nentrer le mot de pass : ");
        scanf(" %[^\n]s", motdepass_user);
        test_motdepass = validation_motdepass(motdepass_user, nom_user);
        if (test_motdepass == 0)
            printf("\nle mot de pass Doit contenir au moins :une lettre majuscule, une lettre minuscule, un chiffre et un caractère spécial (par exemple : !@#$%^&*)");
        else if (test_motdepass == -1)
            printf("\nle mot de pass doit contenir au minimum 8 caractère et ne doit pas contenir le nom de l'utilisateur");
    } while ((test_motdepass == 0) || (test_motdepass == -1));
    strcpy(tableau_utilisateur[nombre_utilisateur].email, email_user);
    strcpy(tableau_utilisateur[nombre_utilisateur].nom, nom_user);
    strcpy(tableau_utilisateur[nombre_utilisateur].prenom, prenom_user);
    tableau_utilisateur[nombre_utilisateur].age = age_user;
    strcpy(tableau_utilisateur[nombre_utilisateur].motdepass, motdepass_user);
    tableau_utilisateur[nombre_utilisateur].role = 3;
    
    nombre_utilisateur++;
    printf("\nvous avez inscrir");
    printf("\nvous pouvez maintement se connecter");
    sign_in();
}
int main()
{
    initialisation_utilisateur();
    initilistaion_reclamation();
    sign_up_in_affichage();
}