/*Ecrire une fonction qui permet de saisir un nombre et qui teste est ce que la somme des chiffres de ce nombre est égale au nombre

Ecrire un algorithme qui génére un nombre premier, l'utilisateur devra déviner ce nombre; aprés 4tentatives si l'utilisateur ne trouve pas, on s'arréte et lui dit vous avez perdu. Si l'utilisateur trouve le nombre on lui pose la question s'il veut continuer s'il dit oui, on génére un autre qu'il dévinera et s'il dit non on arrete le proogramme

Ecrire un algorithme qui permet de saisir deux nombres parfait et le programme doit générer tous les nombres premiers entre ces deux nombres parfaits*/

#include <stdio.h>
#include "fonction.h"
#include <stdlib.h>  
#include <time.h> 
#include <unistd.h>

int saisirnombre(int nombre){
    do
    {
        printf("Entrez un nombre : ");
        scanf("%d", &nombre);
    } while (nombre<0);
    return nombre;
}
int sommeChiffres(int nombre) {
    int nbr= nombre;
    int somme = 0;
    while (nbr != 0) {
        somme += nbr % 10;
        nbr /= 10;
    }

    if (somme== nombre){
        return 1;
    }
    else
    return 0;
}



int estPremier(int nombre){
    if (nombre <= 1) {
        return 0;
    } else {
        for (int i = 2; i * i <= nombre; i++) {
            if (nombre % i == 0) {
                return 0;
                break; 
            }
        }
    }
    return 1;
}
int genererNombrePremier() {
    int nombre;
    do {
        nombre = rand() % 11; // Génère un nombre aléatoire entre 2 et 1001
    } while (!estPremier(nombre));
    return nombre;
}

int deviner(int nombretente){
    int nombreADeviner = genererNombrePremier();
    int trouve= 0;

    for (int i = 1; i <= 4; ++i) {
        printf("Tentative %d : ", i);
        scanf("%d", &nombretente);

        if (nombretente == nombreADeviner) {
            trouve = 1;
            printf("Bravo! Vous avez trouvé le nombre premier %d.\n", nombreADeviner);
            break;
        } else {
            printf("Ce n'est pas le bon nombre.\n");
        }
    }

    if (trouve==0) {
        printf("Désolé, vous avez épuisé toutes vos tentatives. Le nombre premier était %d.\n", nombreADeviner);
    } else {
        char reponse;
        printf("Voulez-vous jouer à nouveau? (O/N): ");
        scanf(" %c", &reponse);
        if (reponse == 'O' || reponse == 'o') {
            nombreADeviner = genererNombrePremier();
            trouve = 0;
            deviner(nombretente); // Relance le jeu
        } else if (reponse == 'N' || reponse == 'n') {
            printf("Merci d'avoir joué!\n");
        }
    }
 return 1;
}


int estParfait(int nombre){
    int sommediviseur=0;
    for ( int i=1; i<= nombre/2; i++){
        if (nombre % i == 0){
            sommediviseur += i;
        }
    }
    if (sommediviseur == nombre) {
            return 1;
        } else {
           return 0;
        }
    return 1;
}
int saisinombreparfait(){
    int nombre;
      do
    {
        printf("Entrez un nombre parfait : ");
        scanf("%d", &nombre);
    if (!estParfait(nombre)){
        printf("Le nombres saisi ne sont pas parfait.\n");
    }
    } while (estParfait(nombre)==0);
    return nombre;
}

int nombresPremiersEntreParfaits (int nombre1, int nombre2){
    printf("Les nombres premiers sont: ");
    if (nombre1 < nombre2){
         for (int i = nombre1 + 1; i < nombre2; i++) {
            if (estPremier(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }else if (nombre2<nombre1){
         for (int i = nombre1 - 1; i >nombre2; i--) {
            if (estPremier(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 1;
}



int saisinombre1(){
    int nombre1;
    do
    {
        printf("Saisir un nombre: \n");
        scanf("%d", &nombre1);
    } while (nombre1<3);

    return nombre1;
}
int saisinombre2(int nombre1){
    int nombre2;
    do
    {
        printf("Saisir un nombre: \n");
        scanf("%d", &nombre2);
        if (nombre2 <3 || nombre2 >nombre1) {
            printf("Le nombre doit être supérieur ou égale à 3 et inférieur à %d.\n", nombre1);
        }
    } while (nombre2<3 || nombre2>nombre1);
    return nombre2;
}
void TriangleIsocele(int nombre1, char couleur){
        int espace, etoile;
        printf("\x1b[%dm", couleur);
        for (int i = 1; i <= nombre1; i++) {
            printf("\t\t\t\t\t\t");
            // Boucle pour afficher les espaces
            for (espace = 1; espace <= nombre1 - i; espace++) {
                printf(" ");
            }
            // Boucle pour afficher les étoiles
            for (etoile = 1; etoile <= 2 * i - 1; etoile++) {
                printf("*");
            }
            printf("\n");
        }
}
void TriangleRectangle(int nombre1, char couleur) {
    printf("\x1b[%dm", couleur);
    for(int i = 1; i <= nombre1; i++) {
        printf("\t\t\t\t\t\t");
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
void carre (int nombre1, char couleur){
    printf("\x1b[%dm", couleur);
    for (int i = 0; i < nombre1; i++) {
        printf("\t\t\t\t\t\t");
        for (int j = 0; j < nombre1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
void rectangle (int nombre1, int nombre2, char couleur){
    printf("\x1b[%dm", couleur);
    for (int i = 0; i < nombre2; i++) {
        printf("\t\t\t\t\t\t");
        for (int j = 0; j < nombre1; j++) {
            printf("* ");
            fflush(stdout); 
            usleep(400000);
        }
        printf("\n");
    }
}
char color(){
    int col;
    char c;
        printf("1 bleu\n");
        printf("2 rouge\n");
        printf("3 vert\n");
        printf("4 jaune\n");
        printf("5 Magenta\n");
        printf("6 Cyan\n");
        printf("saisir une couleur : \n");
        
    do{
    getchar();
    scanf("%c",&c);
    if(c!='1' && c!='2' && c!='3' && c!='4' && c!='5' && c!='6') printf("la couleur doit etre 1,2,3,4,5 ou 6\n");
    }while(c!='1' && c!='2' && c!='3' && c!='4' && c!='5' && c!='6');
    if (c=='1') col=34;
    if (c=='2') col=31;
    if (c=='3') col=32;
    if (c=='4') col=33;
    if (c=='5') col=35;
    if (c=='6') col=36;
    return col;
}
int demandesaisiautrevaleur(){
    int nombre1, nombre2, choixfigure, choixtriangle;
    char choixcouleur;
    nombre1=saisinombre1();
    char reponse;
        printf("Voulez-vous jouer à nouveau? (O/N): \n");
        scanf(" %c", &reponse);
        if (reponse == 'N' || reponse == 'n') {
            puts("**Veuillez choisir la figure que vous souhaitez dessiner**\n");
            puts("                 1--Triangle\n");
            puts("                 2--Carré\n");
            printf("Entrez le numéro du choix de figure:\n");
            scanf("%d", &choixfigure);

            if (choixfigure==1){
                puts("**Veuillez choisir le type de triangle que vous souhaitez dessiner**\n");
                puts("                 1--Triangle isocéle\n");
                puts("                 2--Triangle rectangle\n");
                printf("Entrez le numéro du choix de triangle:\n");
                scanf("%d", &choixtriangle);

                if (choixtriangle==1){
                    choixcouleur=color();
                    TriangleIsocele(nombre1, choixcouleur);
                }
                else if (choixtriangle==2){
                    choixcouleur=color();
                    TriangleRectangle(nombre1, choixcouleur);
                }
                else{
                printf("Le choix n'est pas disponible");
                printf("Entrez le numéro du choix de figure:\n");
                scanf("%d", &choixtriangle);
                }

            }
            else if (choixfigure==2){
                choixcouleur=color();
                carre (nombre1, choixcouleur);
            }
            else{
                printf("Le choix n'est pas disponible");
                printf("Entrez le numéro du choix de triangle:\n");
                scanf("%d", &choixfigure);
            }
            
        } else if (reponse == 'O' || reponse == 'o') {
           nombre2 =saisinombre2(nombre1);

           if (nombre1==nombre2){
                choixcouleur=color();
                carre (nombre1, choixcouleur);
           }
           else {
                choixcouleur=color();
                rectangle (nombre1, nombre2, choixcouleur);
           }
        }
    return 1;
}