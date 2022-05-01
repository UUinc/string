#include <stdio.h>
#include <conio.h>
#include <ctype.h>  
#include "chaine.h"

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

int main()  
{  
    node *chaine = NULL;
    node *chaine2 = NULL;
    printf (" Enter the characters from the keyboard (Press Enter button to stop).\n");  

    chaine = Saisie(chaine);
    Affichage(chaine);
    printf("\nlongueur : %d\n", Longueuer(chaine));

    Affichage(chaine2);
    chaine2 = Copie(chaine);
    Affichage(chaine2);

    Affichage(Concatenation(chaine, chaine2));

    getch();
    return 0;
}