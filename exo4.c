/*: Faire un sous programme qui reçoit qui saisit une date (jour, mois et année) puis détermine et
affiche la date suivante*/
#include <stdio.h>
void anneevalide(int*);
void moisvalide(int *);
void jourvalide (int *);
void datesuivante (int *, int *, int *);
int estBissextile(int);
int anneevalide1(int);
int moisvalide1(int);
int jourvalide1 (int);
int datesuivante1 (int, int, int);



void anneevalide(int *annee){
    do
    {
        printf("Veuillez saisir une année : ");
        scanf("%d", annee);
        if (*annee < 1)
        {
            printf("L'année doit être positive\n");
        }
    } while (*annee < 1);
}
int estBissextile(int annee) {
    anneevalide(annee);
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        printf("L'année est bissextile");
    } else {
        printf("L'année n'est pas bissextile");
    }
}
void moisvalide(int *mois){
    do
    {
        printf("Veuillez saisir une mois : ");
        scanf("%d", mois);
        if (*mois < 1 || *mois > 12) {
            printf("Mois invalide.\n");
        }
    } while (*mois < 1 || *mois > 12);
}
void jourvalide (int *jour){
    int *mois;
    moisvalide(mois);
    int *annee;
    if (*jour < 1 || *jour > 31) {
        printf("Jour invalide.\n");
    }
    if ((*mois == 4 || *mois == 6 || *mois == 9 || *mois == 11) && *jour > 30) {
        printf("Jour invalide pour ce mois.\n");
    }
    if (*mois == 2) {
        if (estBissextile(annee)) {
                if (*jour > 29) {
                printf("Jour invalide pour ce mois (année bissextile).\n");
            }
            } else {
                if (*jour > 28) {
                printf("Jour invalide pour ce mois.\n");
            }
            }
    }
}
void datesuivante (int *jour, int *mois, int *annee){
    jourvalide(jour);
    *jour = *jour + 1;
    if ((*mois == 4 || *mois == 6 || *mois == 9 || *mois == 11) && *jour > 30) {
        *jour = 1;
        *mois = *mois + 1;
    } else if (*mois == 2) {
        if (estBissextile(annee)) {
            if (*jour > 29) {
                *jour = 1;
                *mois = *mois + 1;
            }
        } else {
            if (*jour > 28) {
                *jour = 1;
                *mois = *mois + 1;
            }
        }
    } else if (*jour > 31) {
        *jour = 1;
        *mois = *mois + 1;
        if (*mois > 12) {
            *mois = 1;
            *annee = *annee + 1;
        }
    }
}



int anneevalide1(int annee){
    do
    {
        printf("Veuillez saisir une année : ");
        scanf("%d", annee);
        if (annee < 1)
        {
            printf("L'année doit être positive\n");
        }
    } while (annee < 1);
    return annee;
}
int estBissextile(int annee) {
    annee = anneevalide1(annee);
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        printf("L'année est bissextile");
    } else {
        printf("L'année n'est pas bissextile");
    }
    return annee;
}
int moisvalide1(int mois){
    do
    {
        printf("Veuillez saisir une mois : ");
        scanf("%d", mois);
        if (mois < 1 || mois > 12) {
            printf("Mois invalide.\n");
        }
    } while (mois < 1 || mois > 12);
    return mois;
}
int jourvalide1 (int jour){
    int mois;
    mois =moisvalide1(mois);
    int annee;
    if (jour < 1 || jour > 31) {
        printf("Jour invalide.\n");
    }
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30) {
        printf("Jour invalide pour ce mois.\n");
    }
    if (mois == 2) {
        if (estBissextile(annee)) {
                if (jour > 29) {
                printf("Jour invalide pour ce mois (année bissextile).\n");
            }
            } else {
                if (jour > 28) {
                printf("Jour invalide pour ce mois.\n");
            }
            }
    }
}
int datesuivante1 (int jour, int mois, int annee){
    jour = jourvalide1(jour);
    jour = jour + 1;
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30) {
        jour = 1;
        mois = mois + 1;
    } else if (mois == 2) {
        if (estBissextile(annee)) {
            if (jour > 29) {
                jour = 1;
                mois = mois + 1;
            }
        } else {
            if (jour > 28) {
                jour = 1;
                mois = mois + 1;
            }
        }
    } else if (jour > 31) {
        jour = 1;
        mois = mois + 1;
        if (mois > 12) {
            mois = 1;
            annee = annee + 1;
        }
    }
}


int main (){
    int jour, mois, annee;
    // datesuivante(&jour, &mois, &annee);

    datesuivante1(jour, mois, annee);
    return 0;
}