#include <stdio.h>
#include <conio.h>
#include <ctype.h>  
#include "console.h"
#include "chaine.h"

//functions prototype
int menu();

int main()  
{  
    int choice;

    node* chaine = NULL;
    node* chaine2 = NULL;
    node* chaine3 = NULL;
    int position, taille;

    while(1)
    {
        choice = menu();
        
        clrscr();
        
        switch(choice)
        {
            case 1://Saisie
                fflush(stdin);
                chaine = Saisie(chaine);
                break;
            case 2://Affichage
                Affichage(chaine);
                break;
            case 3://Longueur
                printf("Longueur de la chaine est : %d", Longueuer(chaine));
                break;
            case 4://Copie
                chaine2 = Copie(chaine);
                printf("Bien copier");
                break;
            case 5://Concatenation
                chaine = Concatenation(chaine, chaine2);
                printf("Bien concatene");
                break;
            case 6://Inversion
                chaine = Inversion(chaine);
                printf("Bien inverser");
                break;
            case 7://Insertion
                printf("Donner la position a inserer : ");
                scanf("%d", &position);
                chaine = Insertion(chaine, chaine2, position);
                printf("Bien inserer");
                break;
            case 8://Suppression
                printf("Donner la position a supprimer : ");
                scanf("%d", &position);
                printf("Donner la taille : ");
                scanf("%d", &taille);
                chaine = Suppression(chaine, position, taille);
                printf("Bien supprimer");
                break;
            case 9://Recherche
                Recherche_Info(Recherche(chaine, chaine2));
                break;
            case 10://Remplacer
                printf("find     : ");
                fflush(stdin);
                chaine2 = Saisie(chaine2);
                printf("remplace : ");
                fflush(stdin);
                chaine3 = Saisie(chaine3);
                chaine = Remplacer(chaine, chaine2, chaine3);
                printf("Bien remplacer");
                break;
            case 0:
                exit(0);
        }
        printf("\nretour au menu");
        getch();
        clrscr();
    }
    getch();
    return 0;
}

int menu()
{
    int choice;
    int isError;
    int inputPosition;

    puts("My Word");
    puts("(word processing software)");

    puts("Menu");
    puts(" 1.Saisie");
    puts(" 2.Affichage");
    puts(" 3.Longueur");
    puts(" 4.Copie");
    puts(" 5.Concatenation");
    puts(" 6.Inversion");
    puts(" 7.Insertion");
    puts(" 8.Suppression");
    puts(" 9.Recherche");
    puts("10.Remplacer");
    puts(" 0.Sortir");

    do
    {
        printf(" > ");
        inputPosition = wherey();

        fflush(stdin);
        isError = scanf("%d", &choice);

        //if the input cursor not in the same y position
        if(inputPosition != wherey()-1)
        {
            gotoxy(wherex(), wherey()-1);
            ClearLine();
        }

        if(isError != 0 && choice >= 0 && choice <= 10)
        {
            break;
        }

        gotoxy(wherex(), inputPosition);
        ClearLine();
    }while(1);
}