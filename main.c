#include"header.h"
#include<stdio.h>
#include <string.h>
#include <time.h>
extern int nombre_reclamation;
extern char liste_categories[5][60];


void initilistaion_reclamation()
{
    strcpy(tableau_reclamation[0].email, "client@gmail.com");
    strcpy(tableau_reclamation[0].description , "le materieau et deffectu");
    strcpy(tableau_reclamation[0].motif, "facturation");
    strcpy(tableau_reclamation[0].categorie, "a propos de produit");
    strcpy(tableau_reclamation[0].status, "résolu");
    strcpy(tableau_reclamation[0].date, "23/09/2024");
    tableau_reclamation[0].ID = generation_ID_reclamation();
    nombre_reclamation++;
}
void afficher_reclamation(char email[TAILLE_EMAIL], int role)
{ 
    int i;
    if(utilisateur_actuel->role == 1 || utilisateur_actuel->role == 2)
    {
        for(i = 0; i < nombre_reclamation; i++)
        {
            printf("reclamation ID : %d", tableau_reclamation[i].ID);
            printf("\nl'email : %s", tableau_reclamation[i].email);
            printf("\nla description : %s", tableau_reclamation[i].description);
            printf("\nle motif : %s", tableau_reclamation[i].motif);
            printf("\nle categorie : %s", tableau_reclamation[i].categorie);
            printf("\nle status : %s", tableau_reclamation[i].status);
            printf("\nle date : %s", tableau_reclamation[i].date);
        }
    }
    else
    {
         for(i = 0; i < nombre_reclamation; i++)
         {
             if(strcmp(tableau_reclamation[i].email, utilisateur_actuel->email) == 0)
            {
                printf("reclamation %d :", tableau_reclamation[i].ID);
                printf("\n%s", tableau_reclamation[i].description);
                 printf("\n%s", tableau_reclamation[i].motif);
                printf("\n%S", tableau_reclamation[i].categorie);
                 printf("\n%S", tableau_reclamation[i].date);
                 break;
             }
         }   
    }
    printf("\nclicker entrer pour revenir en arriere");
    getchar();
    menu_reclamations();
}
void ajouter_reclamation()
{
    char date;
    int i, n;
    char desciption_client[TAILLE_DESCIPTION], motif_client[TAILLE_MOTIF];
    printf("\nentrer la discripton de votre reclamation : ");
    scanf(" %[^\n]s", desciption_client);
    printf("\nchoisir la categorie de votre declaration : ");
    for(i = 0; i < 5; i++)
    {
        printf("\n%d  %s", i +1, liste_categories[i]);
    }
    scanf("%d", &n);
    printf("\nentrer le motif de votre reclamation : ");
    scanf(" %[^\n]s", motif_client);

    printf("deboging 1 --- \n");
    tableau_reclamation[nombre_reclamation].ID = generation_ID_reclamation();
    strcpy(tableau_reclamation[nombre_reclamation].description, desciption_client);
    strcpy(tableau_reclamation[nombre_reclamation].categorie, liste_categories[n - 1]);
    strcpy(tableau_reclamation[nombre_reclamation].motif, motif_client);
    strcpy(tableau_reclamation[nombre_reclamation].status, "en cours");
    printf("deboging 2 --- \n");

    time_t t;
   struct tm *tmp;
   // Get the current time
   time(&t); 
   // Convert to local time
   tmp = localtime(&t); 
   // Format the date and time
   strftime(tableau_reclamation[nombre_reclamation].date, sizeof(tableau_reclamation[nombre_reclamation].date), "%x - %I:%M%p", tmp);
   printf("deboging 3 --- \n");
    //strcpy(tableau_reclamation[nombre_reclamation].date, date);
    nombre_reclamation++;


    printf("\t\n ------ %d \n" , nombre_reclamation);
    printf("\t\n ------ %s \n" , tableau_reclamation[nombre_reclamation].description);

    printf("\nclicker entrer pour revenir en arriere");
    getchar();
    menu_reclamations();
}
void modifier_reclamation()
{
    char nouveau_desription[TAILLE_DESCIPTION],  nou_categorie[TAILLE_CATEGORIE];
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