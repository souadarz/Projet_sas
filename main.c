#include "header.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
extern int nombre_reclamation;
extern int nombre_utilisateur;
extern char liste_categories[5][60];

void initilistaion_reclamation()
{
    strcpy(tableau_reclamation[0].email, "client@gmail.com");
    strcpy(tableau_reclamation[0].description, "le materieau et deffectu");
    strcpy(tableau_reclamation[0].motif, "facturation");
    strcpy(tableau_reclamation[0].categorie, "a propos de produit");
    strcpy(tableau_reclamation[0].status, "résolu");
    tableau_reclamation[0].date = time(NULL);
    tableau_reclamation[0].ID = generation_ID_reclamation();
    nombre_reclamation++;
}

void afficher_reclamation(char email[TAILLE_EMAIL], int role)
{
    int i;
    if (role == 1 || role == 2)
    {
        for (i = 0; i < nombre_reclamation; i++)
        {
            printf("reclamation ID : %d", tableau_reclamation[i].ID);
            printf("\nl'email : %s", tableau_reclamation[i].email);
            printf("\nla description : %s", tableau_reclamation[i].description);
            printf("\nle motif : %s", tableau_reclamation[i].motif);
            printf("\nle categorie : %s", tableau_reclamation[i].categorie);
            printf("\nle status : %s", tableau_reclamation[i].status);

            // Convert time_t to struct tm
            struct tm *timeinfo = localtime(&tableau_reclamation[i].date);
            printf("\nle date : %s", asctime(timeinfo));
            
        }
    }
    else
    {
        for (i = 0; i < nombre_reclamation; i++)
        {
            if (strcmp(tableau_reclamation[i].email, email) == 0)
            {
                printf("reclamation %d :", tableau_reclamation[i].ID);
                printf("\nla description : %s", tableau_reclamation[i].description);
                printf("\nle motif : %s", tableau_reclamation[i].motif);
                printf("\nle categorie : %s", tableau_reclamation[i].categorie);

                // Convert time_t to struct tm
                struct tm *timeinfo = localtime(&tableau_reclamation[i].date);
                printf("\nle date : %s", asctime(timeinfo));
                break;
            }
        }
    }
    if(role == 1 || role == 2)
    {
        printf("\nclicker entrer pour revenir en arriere");
        getchar();
        menu_reclamations(email , role);
    }
    else
    {
        printf("\nclicker entrer pour revenir en arriere");
        getchar();
        menu_client(email , role);
    }
}
    void ajouter_reclamation(char email[], int role)
    {
        time_t date, date_reclamation;
        int i, n;
        char desciption_client[TAILLE_DESCIPTION], motif_client[TAILLE_MOTIF];
        printf("\nentrer la discripton de votre reclamation : ");
        scanf(" %[^\n]s", desciption_client);
        printf("\nchoisir la categorie de votre reclamation : \n");
        for (i = 0; i < 5; i++)
        {
            printf("%d  %s\n", i + 1, liste_categories[i]);
        }
        scanf("%d", &n);
        getchar();
        printf("\nentrer le motif de votre reclamation : ");
        scanf(" %[^\n]s", motif_client);
        getchar();
        tableau_reclamation[nombre_reclamation].ID = generation_ID_reclamation();
        strcpy(tableau_reclamation[nombre_reclamation].email, email);
        strcpy(tableau_reclamation[nombre_reclamation].description, desciption_client);
        strcpy(tableau_reclamation[nombre_reclamation].categorie, liste_categories[n - 1]);
        strcpy(tableau_reclamation[nombre_reclamation].motif, motif_client);
        strcpy(tableau_reclamation[nombre_reclamation].status, "en cours");
        // time_t date_reclamation;
        date_reclamation = time(NULL);
        tableau_reclamation[nombre_reclamation].date = date_reclamation;
        nombre_reclamation++;
        if(utilisateur_actuel.role == 1 || utilisateur_actuel.role == 2)
            menu_reclamations();
        else
            menu_client(email , role);
    }
    void modifier_reclamation()
    {
        char nouveau_desription[TAILLE_DESCIPTION], nou_categorie[TAILLE_CATEGORIE];
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
        char email[TAILLE_EMAIL], nouveau_email[TAILLE_EMAIL], nouveau_motdepass[TAILLE_MOTDEPASS], nouveau_nom[TAILLE_NOM],
            nouveau_prenom[TAILLE_PRENOM];
        int i, utilisateur_found = 0, nouveau_role, nouveau_age;
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
        scanf(" %d", nouveau_age);
        printf("\nentrer le nouveau role : ");
        scanf(" %d", nouveau_role);
        for (i = 0; i < nombre_utilisateur; i++)
        {
            if(strcmp(tableau_utilisateur[i].email, email) == 0)
            {
                strcpy(tableau_utilisateur[i].email, nouveau_email);
                strcpy(tableau_utilisateur[i].motdepass, nouveau_motdepass);
                strcpy(tableau_utilisateur[i].nom, nouveau_nom);
                strcpy(tableau_utilisateur[i].prenom, nouveau_prenom);
                tableau_utilisateur[i].age = nouveau_age;
                tableau_utilisateur[i].role = nouveau_role;
                utilisateur_found = 1;
            }
        }
        if(utilisateur_found != 1)
            printf("aucun utilisateur trouver pour cet email");
    }
    void supprimer_utilisateur()
    {
        int i, utilisateur_found = 0;
        char email[TAILLE_EMAIL];
        printf("\nentrer l'email de l'utilisateur a supprimer : ");
        scanf(" %[^\n]s", email);
        for(i = 0; i < nombre_utilisateur; i++)
        {
            if(strcmp(tableau_utilisateur[i].email, email) == 0)
                utilisateur_found = 1;
                  break;
        }
        for(; i < nombre_utilisateur - 1; i++)
            {
                tableau_utilisateur[i] = tableau_utilisateur[i + 1];
            }
            nombre_utilisateur--;
        if(utilisateur_found != 1)
            printf("aucun utilisateur trouver pour cet email");
    }
    void rechercher_utilisateur()
    {
        int i, utilisateur_found = 0;
        char email[TAILLE_EMAIL];
        printf("\nentrer l'email de l'utilisateur a rechercher : ");
        scanf(" %[^\n]s", email);
        for(i = 0; i < nombre_utilisateur; i++)
        {
            if(strcmp(tableau_utilisateur[i].email, email) == 0)
            {
                printf("\nemail : %s", tableau_utilisateur[i].email);
                printf("\nmot de pass : %s", tableau_utilisateur[i].motdepass);
                printf("\nle nom : %s", tableau_utilisateur[i].nom);
                printf("\nle prenom : %s", tableau_utilisateur[i].prenom);
                printf("\nl'age : %d", tableau_utilisateur[i].age);
                printf("\nle role %d", tableau_utilisateur[i].role);
                utilisateur_found = 1;
            }
        }
        if(utilisateur_found != 1)
            printf("aucun utilisateur trouver pour cet email");
    }