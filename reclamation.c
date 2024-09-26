#include "header.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
extern char mot_cle_haute[5][15] ,mot_cle_myenne[5][15], mot_cle_besse[5][15];
extern int nombre_reclamation;
extern int nombre_utilisateur;
extern char liste_categories[5][60];
extern int id_reclamation;

void initilistaion_reclamation()
{

    strcpy(tableau_reclamation[0].email, "client_1@gmail.com");
    strcpy(tableau_reclamation[0].description, "le materieau et deffectu");
    strcpy(tableau_reclamation[0].motif, "facturation");
    strcpy(tableau_reclamation[0].categorie, "a propos de produit");
    strcpy(tableau_reclamation[0].status, "resolu");
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
    strcpy(tableau_reclamation[2].status, "rejete");
    tableau_reclamation[2].date = time(NULL);
    tableau_reclamation[2].ID = generation_ID_reclamation();
    nombre_reclamation++;
    strcpy(tableau_reclamation[3].email, "client@gmail.com");
    strcpy(tableau_reclamation[3].description, "le materieau et deffectu");
    strcpy(tableau_reclamation[3].motif, "facturation");
    strcpy(tableau_reclamation[3].categorie, "a propos de produit");
    strcpy(tableau_reclamation[3].status, "resolu");
    tableau_reclamation[3].date = time(NULL);
    tableau_reclamation[3].ID = generation_ID_reclamation();
    nombre_reclamation++;
}

void afficher_reclamation()
{
    int i;
    system("cls");
    printf("\n##################################################");
    printf("\n             Liste des reclamations");
    printf("\n##################################################\n");
    if (utilisateur_actuel->role == 1 || utilisateur_actuel->role == 2)
    {
        for (i = 0; i < nombre_reclamation; i++)
        {
            printf("\nreclamation ID : %d _ _ _ _ _ _ _ _ _ _ _ _ _ ", tableau_reclamation[i].ID);
            printf("\nl'email : %s", tableau_reclamation[i].email);
            printf("\nla description : %s", tableau_reclamation[i].description);
            printf("\nle motif : %s", tableau_reclamation[i].motif);
            printf("\nle categorie : %s", tableau_reclamation[i].categorie);
            printf("\nle status : %s", tableau_reclamation[i].status);
            if( tableau_reclamation[i].priorite == 1 ){
                printf("\npriorite : haute.");
            }else {
                if( tableau_reclamation[i].priorite == 2 ){
                printf("\npriorite : moyenne.");
            }
            else printf("\npriorite : basse .");
            }

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
                printf("\nreclamation %d :", tableau_reclamation[i].ID);
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
        printf("%d_ %s\n", i + 1, liste_categories[i]);
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
    tableau_reclamation[nombre_reclamation].note[0] = '\0';
    // time_t date_reclamation;
    date_reclamation = time(NULL);
    tableau_reclamation[nombre_reclamation].date = date_reclamation;
    tableau_reclamation[nombre_reclamation].priorite = attribuer_priorite(tableau_reclamation[nombre_reclamation].description);
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
    int n, i, identifiant;
    char new_desription[TAILLE_DESCIPTION], new_categorie[TAILLE_CATEGORIE], new_motif[TAILLE_MOTIF], new_satus[TAILLE_STATUS];
    printf("\nentrer l'identifiant de la reclamation a modifier : ");
    scanf("%d", &identifiant);
    for(i = 0; i < nombre_reclamation; i++)
    {
        if(tableau_reclamation[i].ID == identifiant)
        {
            do
            {
                system("cls");
                printf("\n##################################################");
                printf("\n                   Modifier reclamation");
                printf("\n##################################################\n");
                printf("\nchoisir ce que vous voulez modifier dans la reclamation : ");
                printf("\n0. revenir");
                printf("\n1. modifier la description.");
                printf("\n2. modifier la categorie.");
                printf("\n3. modifier le motif.");
                printf("\n4. modifier le status.");
                scanf("%d", &n);
                switch(n)
                {
                case 0: menu_reclamations();
                case 1: {
                        printf("\nentrer la nouvelle description : ");
                        scanf(" %[^\n]s", new_desription);
                        strcpy(tableau_reclamation[i].description, new_desription);
                         int priorite = attribuer_priorite(tableau_reclamation[nombre_reclamation].description);
                        if( priorite == 1 ){
                            tableau_reclamation[nombre_reclamation].priorite = 1 ;
                        }else{
                            if( priorite == 2 ){
                                tableau_reclamation[nombre_reclamation].priorite = 2 ;
                            }
                            else{
                                tableau_reclamation[nombre_reclamation].priorite = 3;
                            }
                        }
                        break;
                }
                case 2: {
                        printf("\nentrer la nouvelle categorie : ");
                        scanf(" %[^\n]s", new_categorie);
                        strcpy(tableau_reclamation[i].categorie, new_categorie);
                        break;
                }
                case 3: {
                        printf("\nentrer la nouveau motif : ");
                        scanf(" %[^\n]s", new_motif);
                        strcpy(tableau_reclamation[i].motif, new_motif);
                        break;
                    }
                case 4: {
                        printf("\nentrer la nouveau status : ");
                        scanf(" %[^\n]s", new_satus);
                        strcpy(tableau_reclamation[i].status, new_satus);
                        break;
                    }
                default: printf("\nessayer d'entrer un nombre se trouve dand la liste");
                    break;
                }
            }while(n != 0);
        }
    }
    printf("\nclicker entrer pour revenir en arriere");
    getchar();
    menu_reclamations();
}
void supprimer_reclamation()
{
    int i, identifiant, identifiant_found = 0;
    printf("\nentrer l'identifiant de la reclamation a suppimer :  ");
    scanf("%d", &identifiant);
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
    if(identifiant_found == 1)
        nombre_reclamation--;
    else
        printf("\naucune reclamation trouver pour cet identiant");
    printf("\nclicker entrer pour revenir en arriere");
    getchar();
    menu_reclamations();
}
void traiter_reclamation()
{
    char note[1000], new_status[TAILLE_STATUS];
    int i, identifiant;
    printf("\nentrer identifiant de la reclamation a traiter : ");
    scanf("%d", &identifiant);
    for(i = 0; i < nombre_reclamation; i++)
    {
        if(tableau_reclamation[i].ID == identifiant)
        {
            printf("\entrer le nouveau status : ");
            scanf(" %[^\n]s", new_status);
            printf("\nentrer les notes a ajouter : ");
            scanf(" %[^\n]s", note);
            strcpy(tableau_reclamation[i].status, new_status);
            strcpy(tableau_reclamation[i].note, note);
        }
    }
    printf("\nclicker entrer pour revenir en arriere");
    getchar();
    menu_reclamations();
}
void rechercher_reclamation()
{
    int n;
    system("cls");
    printf("\n##################################################");
    printf("\n              Rechercher reclamation");
    printf("\n##################################################\n");
    printf("\nchoisir l'option par laquelle vous voullez faire la recherche  : ");
    printf("\n0. revenir");
    printf("\n1. recherche par identifiant de la reclamation(ID)");
    printf("\n2. recherche par le nom de l'utilisateur");
    //printf("\n3. recherche par email de l'utilisataeu");
    scanf("%d", &n);
    switch(n)
    {
        case 0: menu_reclamations();
        case 1: rechercher_reclamation_ID(); break;
        case 2: rechercher_reclamation_nom(); break;
        //case 3: rechercher_reclamation_date(); break;
        default: printf("\n essayer d'entrer un nombre se trouve dans la liste");
    }
}

void rechercher_reclamation_ID()
{
    int identifiant, i;
    printf("\nentrer l'identifiant de la reclamation(ID) a rechercher  : ");
    scanf("%d", &identifiant);
    getchar();
    system("cls");
    printf("\n##################################################");
    printf("\n          Liste des reclamations trouvees");
    printf("\n##################################################\n");
    for(i = 0; i < nombre_reclamation; i++)
    {
        if(tableau_reclamation[i].ID == identifiant)
        {   
            printf("\nreclamation ID : %d _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ", tableau_reclamation[i].ID);
            printf("\nl'email : %s", tableau_reclamation[i].email);
            printf("\nla description : %s", tableau_reclamation[i].description);
            printf("\nle motif : %s", tableau_reclamation[i].motif);
            printf("\nle categorie : %s", tableau_reclamation[i].categorie);
            printf("\nle status : %s", tableau_reclamation[i].status);
        }
    }
    printf("\nclicker entrer pour revenir en arriere");
    getchar();
    rechercher_reclamation();
}
void rechercher_reclamation_nom()
{
    int i;
    char nom[TAILLE_NOM], prenom[TAILLE_PRENOM];
    printf("\nentrer le nom de l'utilisateur que vous voulez rechercher ses reclamations  : ");
    scanf(" %[^\n]s", nom);
    getchar();
    for(i = 0; i < nombre_utilisateur; i++)
    {
        if((strstr(tableau_utilisateur[i].nom, nom) != NULL) || (strstr(tableau_utilisateur[i].prenom, prenom) != NULL))
        {
            trouver_reclamation(tableau_utilisateur[i].email);
        }
    }
    printf("\nclicker entrer pour revenir en arriere");
    getchar();
    rechercher_reclamation();
}
/*void rechercher_reclamation_date()
{
    int i;
    char datee[50] ;
    printf("\nentrer la date de la reclamation a rechercher (sous la forme jj-mm-yyyy) : ");
    scanf(" %[^\n]s", datee);

    for( i=0 ; i<nombre_reclamation ; i++){
        if( strcmp(datee,asctime(localtime(&tableau_reclamation[i].date)) == 0 )){
            printf("\nreclamation ID : %d _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ", tableau_reclamation[i].ID);
            printf("\nl'email : %s", tableau_reclamation[i].email);
            printf("\nla description : %s", tableau_reclamation[i].description);
            printf("\nle motif : %s", tableau_reclamation[i].motif);
            printf("\nle categorie : %s", tableau_reclamation[i].categorie);
            printf("\nle status : %s", tableau_reclamation[i].status);
        }
    }

}*/
// a revoiiiiir
int attribuer_priorite(char description[TAILLE_DESCIPTION])
{
    //haute : priorite = 1;
    //moyenne : priorite = 2
    //basse : priorite = 3;
    int priorite = 3, j;
        for(j = 0; j < nombre_reclamation; j++)
        {
            if(strstr(tableau_reclamation[j].description, mot_cle_haute[j]) != NULL)
                return 1 ;
        }
        for(j = 0; j < nombre_reclamation; j++)
        {  
            if(strstr(tableau_reclamation[j].description, mot_cle_myenne[j]) != NULL)
                return 2;
        }
    return 3;
}
void trier_reclamation(){
    int i, j;
    reclamation temp_reclamation;
    for(i = 0; i < nombre_reclamation; i++)
    {
        for(j = i + 1; j < nombre_reclamation - 1; j++)
        {
            if(tableau_reclamation[i].priorite > tableau_reclamation[j].priorite)
            {
                temp_reclamation = tableau_reclamation[i];
                tableau_reclamation[i] = tableau_reclamation[j];
                tableau_reclamation[j] = temp_reclamation;
            }
        }
    } 
}
void trouver_reclamation(char email[TAILLE_EMAIL])
{
    int i;
    system("cls");
    printf("\n##################################################");
    printf("\n        Liste des reclamations trouvees");
    printf("\n##################################################\n");
    for(i = 0; i < nombre_reclamation; i++)
    {
        if(strcmp(tableau_reclamation[i].email, email) == 0)
        {
            printf("\nreclamation ID : %d _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ", tableau_reclamation[i].ID);
            printf("\nl'email : %s", tableau_reclamation[i].email);
            printf("\nla description : %s", tableau_reclamation[i].description);
            printf("\nle motif : %s", tableau_reclamation[i].motif);
            printf("\nle categorie : %s", tableau_reclamation[i].categorie);
            printf("\nle status : %s", tableau_reclamation[i].status);
        }
    }
}