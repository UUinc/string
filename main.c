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
    
    printf ("Enter 1 : ");  
    chaine = Saisie(chaine);
    printf ("Enter 2 : ");  
    chaine2 = Saisie(chaine2);

    Recherche(chaine, chaine2);

    getch();
    return 0;
}