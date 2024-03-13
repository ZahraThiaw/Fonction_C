/*Reprendre l'exo2 en remplaçant les if par des switch*/

#include <stdio.h>

int anneepositive(int annee)
{
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
int annebissextile(int annee)
{
    
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
    {
        return 1;
    }
    return 0;
}
int moisvalide(int mois)
{
    do
    {
        printf("Entrez le mois (1-12) : ");
        scanf("%d", &mois);
        if (mois < 1 || mois > 12)
        {
            printf("Mois invalide.\n");
        }
    } while (mois < 1 || mois > 12);
    return mois;
}
int nombrejourmois(int annee, int mois)
{
    
    switch (mois)
    {
    case 2:
        if (annebissextile(annee))
        {
            return 29;
            break;
        }
        else
        {
            return 28;
            break;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    default:
        return 31;
        break;
    }
    return 1;
}

int main()
{
    int annee, mois;
    // anneepositive(annee);
    // moisvalide(mois);
    // nombrejourmois(annee, mois);
    printf("Le nombre de jours est : %d\n", nombrejourmois(anneepositive(annee), moisvalide(mois)));
    return 0;
}