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
    
    printf ("Enter : ");  
    chaine = Saisie(chaine);

    printf("\n");
    Affichage(chaine);

    chaine = Suppression(chaine, 2, 5);

    printf("\n");
    Affichage(chaine);

    getch();
    return 0;
}