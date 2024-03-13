/*Faire un sous programme qui reçoit une date (jour, mois et année) puis détermine et affiche la
date précédente*/

#include <stdio.h>

int saisiannee(int annee){
    do
    {
        printf("Entrez l'année : ");
        scanf("%d", &annee);
    } while (annee<1);
}
int estBissextile(int annee) {
    annee= saisiannee(annee);
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        printf("L'année est bissextile");
    } else {
        printf("L'année n'est pas bissextile");
    }
}
int saisimois(int mois){
    do
    {
        printf("Entrez le mois : ");
        scanf("%d", &mois);
    } while (mois<1 || mois > 12);
}
int saisijour(int jour){
    int mois, annee;
    int validejour=1;
    do
    {
        printf("Entrez le jour : ");
        scanf("%d", &jour);

        if (jour < 1 || jour > 31) {
        printf("Jour invalide.\n");
        validejour=0;
        }
        if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30) {
            printf("Jour invalide pour ce mois.\n");
            validejour=0;
        }
        if (mois == 2) {
            if (estBissextile(annee)) {
                    if (jour > 29) {
                    printf("Jour invalide pour ce mois (année bissextile).\n");
                    validejour=0;
                }
                } else {
                    if (jour > 28) {
                    printf("Jour invalide pour ce mois.\n");
                    validejour=0;
                }
                }
        }
    } while ( validejour=0);
}
int datesuivante(int jour, int mois, int annee){
     if (jour == 1) {
        if (mois == 1) {
            jour = 31;
            mois = 12;
            annee=annee-1;
        } else {
            mois=mois-1;
            if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
                jour = 30;
            } else if (mois == 2) {
                if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
                    jour = 29;
                } else {
                    jour = 28;
                }
            } else {
                jour = 31;
            }
        }
    } else {
        jour=jour-1;
    }
}

int main (){
    int jour, mois, annee;
    saisiannee(annee);
    estBissextile(annee);
    saisimois(mois);
    saisijour(jour);
    datesuivante(jour, mois, annee);

    return 0;
}