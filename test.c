#include"header.h"
#include<stdio.h>
#include<string.h>
#include<unistd.h>

void sign_up_in_affichage();
void menu_1(){};
void menu_2(){};
void menu_3(){};
void sign_up();
void initialisation()
{
        //les informations du admin
    strcpy(tableau_utilisateur[0].email, "admin@gmail.com");
    strcpy(tableau_utilisateur[0].motdepass,"12ABcd@#");
    strcpy(tableau_utilisateur[0].nom , "mohamed");
    strcpy(tableau_utilisateur[0].prenom , "boclet");
    tableau_utilisateur[0].age = 35;
    tableau_utilisateur[0].role = 1;
    }

int valider_email(char email[TAILLE_EMAIL])
{
    int i,arobase_found = 0, point_found = 0;
    for(i = 0; email[i] != '\0'; i++)
    {
        if(email[i] == '@')
            arobase_found = 1;
        if(point_found)
            return(1);
        if(arobase_found && email[i] == '.')
            point_found = 1;
    }
    return(0);
}

void sign_in()
{
    int i, nombre_essye = 0;
    char email_user[TAILLE_EMAIL], motdepass_user[TAILLE_MOTDEPASS];
    printf("\nentrer l'email : ");
    scanf(" %[^\n]s", email_user);
    for(i = 0; i <= nombre_utilisateur; i++)
    {
        if(strcmp(email_user, tableau_utilisateur[i].email) == 0)
            {
                do
                {
                    printf("\nentrer le mot de pass : ");
                    scanf(" %[^\n]s", motdepass_user);
                    if(strcmp(motdepass_user, tableau_utilisateur[i].motdepass) == 0)
                        {
                            if(tableau_utilisateur[i].role == 1)
                                menu_1();
                            else if(tableau_utilisateur[i].role == 2)
                                menu_2();
                            else
                                menu_3();
                        }
                    else
                    {
                        printf("mot de pass incorect,esseyer une autre fois :");
                        nombre_essye ++;
                    }
                }while(nombre_essye < 3);
              
                        if (nombre_essye == 3)
                        {
                            printf("esseyer de nouveau dans une heure\n");
                            sleep(3600);
                            nombre_essye = 0;
                            sign_up_in_affichage();
                        }
            }
    }
}

void sign_up_in_affichage()
{
    int choix;
    printf("\n1. sign up");
    printf("\n2. sign in");
    printf("\nchoisir un nombre : ");
    scanf("%d", &choix);
    switch(choix){
        case 1: sign_up(); break;
        case 2: sign_in(); break;
        default: printf("\nesseyer de choisir un  nombre se trouvre dans la liste");
    }
}

void sign_up(){char email_user[TAILLE_EMAIL], motdepass_user[TAILLE_MOTDEPASS];
    int i, age, valide = 0;
    do{
        printf("entrer l'email : ");
        scanf(" %[^\n]s", email_user);
    }while(valider_email == 0);
    for(i = 0; i <= nombre_utilisateur; i++)
    {
        if(strcmp(email_user, tableau_utilisateur[i].email) != 0)
            valide = 1;
    }
    if(valide)
    {
        strcpy(tableau_utilisateur[nombre_utilisateur].email, email_user);
        printf("entrer le nom : ");
        scanf(" %[^\n]s", tableau_utilisateur[nombre_utilisateur].nom);
        printf("entrer le prenom : ");
        scanf(" %[^\n]s", tableau_utilisateur[nombre_utilisateur].prenom);
        printf("entrer l'age : ");
        scanf("%d", &tableau_utilisateur[nombre_utilisateur].age);
        printf("entrer le mot de pass : ");
        scanf(" %[^\n]s", motdepass_user);
        if(validation_motdepass(motdepass_user, tableau_utilisateur[nombre_utilisateur].nom) != 0)
        {

        }
    }
}