#include "header.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

extern int nombre_reclamation;
extern int nombre_utilisateur;
extern char liste_categories[5][60];
extern int id_reclamation;

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
    strcpy(tableau_reclamation[1].email, "client_1@gmail.com");
    strcpy(tableau_reclamation[1].description, "jjjjjjjjjjjjjjjj");
    strcpy(tableau_reclamation[1].motif, "kkkkkkkkkkkkk");
    strcpy(tableau_reclamation[1].categorie, "gggggggggggg");
    strcpy(tableau_reclamation[1].status, "en cours");
    tableau_reclamation[1].date = time(NULL);
    tableau_reclamation[1].ID = generation_ID_reclamation();
    nombre_reclamation++;
    strcpy(tableau_reclamation[2].email, "client_2@gmail.com");
    strcpy(tableau_reclamation[2].description, "aaaaaaaaaaaaaa");
    strcpy(tableau_reclamation[2].motif, "bbbbbbbbbbbb");
    strcpy(tableau_reclamation[2].categorie, "bbbbbbbbbbbbbbbbb");
    strcpy(tableau_reclamation[2].status, "rejeté");
    tableau_reclamation[2].date = time(NULL);
    tableau_reclamation[2].ID = generation_ID_reclamation();
    nombre_reclamation++;
}

void afficher_reclamation()
{
    int i;
    if (utilisateur_actuel->role == 1 || utilisateur_actuel->role == 2)
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
            if (strcmp(tableau_reclamation[i].email, utilisateur_actuel->email) == 0)
            {
                printf("reclamation %d :", tableau_reclamation[i].ID);
                printf("\nla description : %s", tableau_reclamation[i].description);
                printf("\nle motif : %s", tableau_reclamation[i].motif);
                printf("\nle categorie : %s", tableau_reclamation[i].categorie);

                // Convert time_t to struct tm
                struct tm *timeinfo = localtime(&tableau_reclamation[i].date);
                printf("\nle date : %s", asctime(timeinfo));
            }
        }
    }
    if (utilisateur_actuel->role == 1 || utilisateur_actuel->role == 2)
    {
        printf("\nclicker entrer pour revenir en arriere");
        getchar();
        menu_reclamations();
    }
    else
    {
        printf("\nclicker entrer pour revenir en arriere");
        getchar();
        menu_client();
    }
}
void ajouter_reclamation()
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
    strcpy(tableau_reclamation[nombre_reclamation].email, utilisateur_actuel->email);
    strcpy(tableau_reclamation[nombre_reclamation].description, desciption_client);
    strcpy(tableau_reclamation[nombre_reclamation].categorie, liste_categories[n - 1]);
    strcpy(tableau_reclamation[nombre_reclamation].motif, motif_client);
    strcpy(tableau_reclamation[nombre_reclamation].status, "en cours");
    // time_t date_reclamation;
    date_reclamation = time(NULL);
    tableau_reclamation[nombre_reclamation].date = date_reclamation;
    nombre_reclamation++;
    if (utilisateur_actuel->role == 1 || utilisateur_actuel->role == 2)
    {
        printf("\nclicker entrer pour revenir en arriere");
        getchar();
        menu_reclamations();
    }
    else
    {
        printf("\nclicker entrer pour revenir en arriere");
        getchar();
        menu_client();
    }
}
void modifier_reclamation()
{
    char nouveau_desription[TAILLE_DESCIPTION], nou_categorie[TAILLE_CATEGORIE];
}
void supprimer_reclamation()
{
    int i, identifiant, identifiant_found = 0;
    printf("entrer l'identifiant de la reclamation a suppimer :  ");
    scanf("%d", identifiant);
    for(i = 0; i < nombre_reclamation; i++)
    {
        if(tableau_reclamation[i].ID == identifiant)
        {
            identifiant_found = 1;
            break;
        }
    }
    for(; i < nombre_reclamation - 1; i++)
    {
        tableau_reclamation[i] = tableau_reclamation[i + 1];
    }
    if(identifiant != 1)
        nombre_reclamation--;
    else
        printf("\naucune reclamation trouver pour cet identiant");
}
void traiter_reclamation()
{
    printf("traiter");
}
void rechercher_reclamation()
{
    int n;
    printf("\nchoisir l'option par laquelle vous voullez faire la recherche  : ");
    printf("\n1. recherche par identifiant de la reclamation(ID)");
    printf("\n2. recherche par le nom dde l'utilisateur");
    printf("\n3. recherche par email de l'utilisataeu");
    scanf("%d", &n);
    switch(n)
    {
        case 1: rechercher_reclamation_ID(); break;
        case 2: rechercher_reclamation_nom(); break;
        case 3: rechercher_reclamation_email(); break;
        default: printf("\n essayer d'entrer un nombre se trouve dans la liste");
    }
}

void rechercher_reclamation_ID()
{
    int identifiant;
    printf("entrer l'identifiant de la reclamation(ID) a rechrcher  : ");
    scanf("%d", identifiant);
}

