#include <stdio.h>
#include <conio.h>
#include "chaine.h"


int main()
{
    char c;
    node* chaine = NULL;

    printf("Enter character: ");
    chaine = Saisie(chaine);
    Affichage(chaine);

    getch();
    return 0;
}