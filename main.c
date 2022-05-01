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
    
    printf ("Enter the characters from the keyboard (Press Enter button to stop).\n");  
    chaine = Saisie(chaine);

    printf("\n");
    Affichage(chaine);

    printf ("\nEnter the characters from the keyboard (Press Enter button to stop).\n");  
    chaine2 = Saisie(chaine2);

    chaine = Insertion(chaine, chaine2, 2);

    printf("\n");
    Affichage(chaine);

    getch();
    return 0;
}