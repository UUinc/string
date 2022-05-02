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
    node *chaine3 = NULL;
    
    printf ("Enter   : ");  
    chaine = Saisie(chaine);
    printf ("Find    : ");  
    chaine2 = Saisie(chaine2);
    printf ("Replace : ");  
    chaine3 = Saisie(chaine3);

    puts("");
    Affichage(chaine);

    chaine = Remplacer(chaine, chaine2, chaine3);

    puts("\n----");
    Affichage(chaine);
    

    getch();
    return 0;
}