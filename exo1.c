/*Faire un sous programme qui reçoit une année puis indique si l’année est bissextile ou pas.*/


#include <stdio.h>
int anneepositive1 (int);
void anneepositive (int*);
int annebissextile (int);
void annebissextile1 (int*);


int anneepositive1 (int annee1) {
    do
    {
        printf("Veuillez saisir une année : ");
        scanf("%d", &annee1);
        if (annee1 < 1)
        {
            printf("L'année doit être positive\n");
        }
    } while (annee1 < 1);
    return annee1;
}

void anneepositive (int *annee) {
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


void annebissextile1 (int *annee1){
    anneepositive(annee1);
    if ((*annee1 % 4 == 0 && *annee1 % 100 != 0) || (*annee1 % 400 == 0)) {
        printf("%d est une année bissextile.\n", *annee1);
    } else {
        printf("%d n'est pas une année bissextile.\n", *annee1);
    }
}

int annebissextile (int annee){
    annee =anneepositive1 (annee);
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        printf("%d est une année bissextile.\n", annee);
    } else {
        printf("%d n'est pas une année bissextile.\n", annee);
    }
    return 1;
}

int main (){
    int annee;
    annee=annebissextile(annee);
    return 0;
}