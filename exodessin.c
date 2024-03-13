#include <stdio.h>


int saisinombre1(int nombre1){
    do
    {
        printf("Saisir un nombre: \n");
        scanf("%d", &nombre1);
    } while (nombre1<3);

    return 1;
}
int saisinombre2(int nombre2){
    int nombre1=saisinombre1(nombre2);
    do
    {
        printf("Saisir un nombre: \n");
        scanf("%d", &nombre2);
    } while (nombre2>nombre1);

    return 1;
}

int demandesaisiautrevaleur(){
    int nombre1, nombre2, choixfigure, choixcouleur, choixtriangle;
    saisinombre1(nombre1);
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
                    void TriangleIsocele(int nombre1){
                        int i, j, espace = 1;
                        espace = nombre1 - 1;
                        for (j = 1; j <= nombre1; j++) {
                            for (i = 1; i <= espace; i++){
                                printf(" ");
                                espace--;
                            }
                            for (i = 1; i <= 2 * j - 1; i++){
                                printf("*");
                            }                            
                            printf("\n");
                        }
                }
                else if (choixtriangle==2){
                    void TriangleRectangle(int nombre1) {
                    for (int i = 1; i <= nombre1; i++) {
                            for (int j = 1; j <= i; j++) {
                                if (j == (nombre1 / 2) + 1 && i == nombre1) {
                                    printf("*"); // Changer la couleur en jaune pour le dernier astérisque
                                } else {
                                    printf("* ");
                                }
                            }
                            printf("\n");
                        }
                    }
                }
            }
            else if (choixfigure==2){
                void carre (int nombre1){
                    for (int i = 0; i < nombre1; i++) {
                        for (int j = 0; j < nombre1; j++) {
                            // Si on est sur le bord du carré, dessiner un *
                            if (int i == 0 || i == nombre1 - 1 || j == 0 || j == nombre1 - 1) {
                                printf("* ");
                            } else {
                                printf("  "); // Sinon, dessiner un espace
                            }
                        }
                        printf("\n"); // Passer à la ligne suivante après avoir fini une ligne du carré
                    }
                }
            }
            
        } else if (reponse == 'O' || reponse == 'o') {
           saisinombre2(nombre2);

           if (nombre1==nombre2){
                void carre (int nombre1){
                    for (int i = 0; i < nombre1; i++) {
                        for (int j = 0; j < nombre1; j++) {
                            if (int i == 0 || i == nombre1 - 1 || j == 0 || j == nombre1 - 1) {
                                printf("* ");
                            } else {
                                printf("  ");
                            }
                        }
                        printf("\n");
                    }
                }
           }
           else {
                void rectangle (int nombre1, int nombre2){
                    for(int i = 0; i < nombre2; i++) {
                    for(int j = 0; j < nombre1; j++) {
                        if (i == 0 || i == nombre2 - 1 || j == 0 || j == nombre1 - 1)
                            printf("* ");
                        else
                            printf("  ");
                    }
                    printf("\n");
                }
                }
           }
        }
    return 1;
}


int main(){

    demandesaisiautrevaleur();
return 0;
}