/*Faire un sous programme qui reçoit une date (jour, mois et année) puis indique si la date est valide
ou pas.*/
#include <stdio.h>
void saisijour (int *);
void saisimois (int *);
void saisiannee (int *);
void datevalide (int*, int*, int*);
int saisijour1 (int);
int saisimois1 (int);
int saisiannee1 (int);
int datevalide1 (int, int, int);



void saisijour (int *jour){
    printf("Entrez un jour:\n");
    scanf("%d", jour);
}
void saisimois (int *mois){
    printf("Entrez un mois:\n");
    scanf("%d", mois);
}
void saisiannee (int *annee){
    printf("Entrez une année:\n");
    scanf("%d", annee);
}
void datevalide (int *jour, int *mois, int *annee){
      if (*annee < 1){
        printf("La date n'est pas valide. \n");
    } else {
            if ((*mois >= 1 && *mois <= 12) && (*jour >= 1)) {
            int joursDansMois = 31;
            if (*mois == 4 || *mois == 6 || *mois == 9 || *mois == 11) {
                joursDansMois = 30;
            } else if (*mois == 2) {
                if ((*annee % 4 == 0 && *annee % 100 != 0) || (*annee % 400 == 0)) {
                    joursDansMois = 29;
                } else {
                    joursDansMois = 28;
                }
            }
            if (*jour <= joursDansMois) {
                printf("La date est valide.\n");
            } else {
                printf("La date n'est pas valide.\n");
            }
        } else {
            printf("La date n'est pas valide.\n");
        }
    }
}



int saisijour1 (int jour){
    printf("Entrez un jour:\n");
    scanf("%d", &jour);
}
int saisimois1 (int mois){
    printf("Entrez un mois:\n");
    scanf("%d", &mois);
}
int saisiannee1 (int annee){
    printf("Entrez une année:\n");
    scanf("%d", &annee);
}
int estBissextile(int annee) {
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        return 1; // L'année est bissextile
    } else {
        return 0; // L'année n'est pas bissextile
    }
}
int datevalide1 (int jour, int mois, int annee){
      if (annee < 1){
        return 0;
    } else {
            if ((mois >= 1 && mois <= 12) && (jour >= 1)) {
            int joursDansMois = 31;
            if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
                joursDansMois = 30;
            } else if (mois == 2) {
                if (estBissextile(annee)) {
                    joursDansMois = 29;
                } else {
                    joursDansMois = 28;
                }
            }
            if (jour <= joursDansMois) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

int main (){
    int jour, mois, annee;
    saisijour (&jour);
    saisimois (&mois);
    saisiannee(&annee);
    datevalide(&jour, &mois, &annee);
    
    jour= saisijour1(jour);
    mois=saisimois1(mois);
    annee= saisiannee1(annee);
     if (datevalide1(jour, mois, annee)) {
        printf("La date est valide.\n");
    } else {
        printf("La date n'est pas valide.\n");
    }

    return 0;
}