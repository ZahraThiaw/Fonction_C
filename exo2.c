/*Faire un sous programme qui reçoit une année et un mois puis détermine et affiche le nombre de
jours de ce mois dans cette année .*/

#include <stdio.h>
int anneepositive (int);
int moisvalide (int);
int nombrejourmois(int, int);
void anneepositive1 (int*);
void moisvalide1 (int*);
void nombrejourmois1 (int*, int *);


int anneepositive (int annee) {
    do
    {
        printf("Veuillez saisir une année : ");
        scanf("%d", &annee);
        if (annee < 1)
        {
            printf("L'année doit être positive\n");
        }
    } while (annee < 1);
    return annee;
}
int moisvalide (int mois){
    do
    {
        printf("Entrez le mois (1-12) : ");
        scanf("%d", &mois);
        // Vérification de la validité du mois
        if (mois < 1 || mois > 12) {
            printf("Mois invalide.\n");
        }
    } while (mois < 1 || mois > 12);
    return mois;
}
int nombrejourmois (int annee, int mois){
    int jours;
        if (mois == 2) {
            if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
                jours = 29;
            else
                jours = 28;
        } else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
            jours = 30;
        } else {
            jours = 31;
        }
    // Affichage du nombre de jours
    printf("Le mois %d de l'annee %d comporte %d jours.\n", mois, annee, jours);
    return 1;
}



void anneepositive1 (int *annee1) {
    do
    {
        printf("Veuillez saisir une année : ");
        scanf("%d", annee1);
        if (*annee1 < 1)
        {
            printf("L'année doit être positive\n");
        }
    } while (*annee1 < 1);
}
void moisvalide1 (int *mois1){
    do
    {
        printf("Entrez le mois (1-12) : ");
        scanf("%d", mois1);
        // Vérification de la validité du mois
        if (*mois1 < 1 || *mois1 > 12) {
            printf("Mois invalide.\n");
        }
    } while (*mois1 < 1 || *mois1 > 12);
}
void nombrejourmois1 (int *annee, int *mois){
    int *jours;
        if (*mois == 2) {
            if ((*annee % 4 == 0 && *annee % 100 != 0) || (*annee % 400 == 0))
                *jours = 29;
            else
                *jours = 28;
        } else if (*mois == 4 || *mois == 6 || *mois == 9 || *mois == 11) {
            *jours = 30;
        } else {
            *jours = 31;
        }
    // Affichage du nombre de jours
    printf("Le mois %d de l'annee %d comporte %d jours.\n", *mois, *annee, *jours);
}

int main (){
    int annee, mois;
    annee= anneepositive(annee);
    mois=moisvalide(mois);
    nombrejourmois(annee, mois);

    anneepositive1(&annee);
    moisvalide1(&mois);
    nombrejourmois1(&annee, &mois);    
    return 0;
}