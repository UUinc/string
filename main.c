#include <stdio.h>
#include <conio.h>
#include <ctype.h>  
#include "console.h"
#include "ui.h"
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

    //change background and fore color
    consolecolor("F", "0");

    //maximize window
    MaximizeOutputWindow();

    //change font size
    FontSize(26);

    while(1)
    {
        choice = menu();
        
        if(choice == 0)
        {
            exit(0);
        }

        clrscr();

        rect(ConsoleWidth() - 5, ConsoleHeight() - 5, 1, 1);
        gotoxy(5, 3);
        
        switch(choice)
        {
            case 1://Saisie
                printf("Entrez la chaine principale : ");
                //make sure that the pointer is empty
                chaine = Clear(chaine);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine = Saisie(chaine);
                break;
            case 2://Affichage
                Affichage(chaine);
                printf("\n");
                break;
            case 3://Longueur
                printf("Longueur de la chaine principale est : %d\n", Longueuer(chaine));
                break;
            case 4://Copie
                printf("la chaine principale va etre copiee dans une autre chaine 2\n");
                //make sure that the pointer is empty
                chaine2 = Clear(chaine2);
                chaine2 = Copie(chaine);

                gotoxy(5, wherey());
                printf("Bien copier\n\n");
                
                //print the result
                gotoxy(5, wherey());
                printf("Chaine principale : ");
                gotoxy(5, wherey()+1);
                printf(" > ");
                Affichage(chaine);
                printf("\n");

                gotoxy(5, wherey());
                printf("Chaine n\xF8""2     : ");
                gotoxy(5, wherey()+1);
                printf(" > ");
                Affichage(chaine);
                printf("\n");
                break;
            case 5://Concatenation
                //enter the first string
                printf("Entrez la chaine principale : ");
                //make sure that the pointer is empty
                chaine = Clear(chaine);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine = Saisie(chaine);

                //enter the second string
                gotoxy(5, wherey());
                printf("Entrez la chaine n\xF8""2     : ");
                //make sure that the pointer is empty
                chaine2 = Clear(chaine2);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine2 = Saisie(chaine2);

                chaine = Concatenation(chaine, chaine2);
                gotoxy(5, wherey());
                printf("Bien concatene\n\n");

                //print the result
                gotoxy(5, wherey());
                printf("Chaine concatene : ");
                gotoxy(5, wherey()+1);
                printf(" > ");
                Affichage(chaine);
                printf("\n");
                break;
            case 6://Inversion
                chaine = Inversion(chaine);
                printf("Bien inverser\n\n");

                //print the result
                gotoxy(5, wherey());
                printf("Chaine inverser : ");
                gotoxy(5, wherey()+1);
                printf(" > ");
                Affichage(chaine);
                printf("\n");
                break;
            case 7://Insertion
                //enter the first string
                printf("Entrez la chaine principale : ");
                //make sure that the pointer is empty
                chaine = Clear(chaine);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine = Saisie(chaine);

                //enter the second string
                gotoxy(5, wherey());
                printf("Entrez la chaine a inserer  : ");
                //make sure that the pointer is empty
                chaine2 = Clear(chaine2);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine2 = Saisie(chaine2);

                gotoxy(5, wherey());
                printf("Donner la position a inserer : ");
                scanf("%d", &position);
                chaine = Insertion(chaine, chaine2, position);
                gotoxy(5, wherey());
                printf("Bien inserer\n\n");

                //print the result
                gotoxy(5, wherey());
                printf("Chaine apres l'insertion : ");
                gotoxy(5, wherey()+1);
                printf(" > ");
                Affichage(chaine);
                printf("\n");
                break;
            case 8://Suppression
                printf("Donner la position a supprimer : ");
                scanf("%d", &position);
                gotoxy(5, wherey());
                printf("Donner la taille : ");
                scanf("%d", &taille);
                chaine = Suppression(chaine, position, taille);
                gotoxy(5, wherey());
                printf("Bien supprimer\n\n");

                //print the result
                gotoxy(5, wherey());
                printf("Chaine apres la suppression : ");
                gotoxy(5, wherey()+1);
                printf(" > ");
                Affichage(chaine);
                printf("\n");
                break;
            case 9://Recherche
                //enter the first string
                printf("Entrez la chaine principale   : ");
                //make sure that the pointer is empty
                chaine = Clear(chaine);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine = Saisie(chaine);

                //enter the second string
                gotoxy(5, wherey());
                printf("Entrez la chaine a rechercher : ");
                //make sure that the pointer is empty
                chaine2 = Clear(chaine2);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine2 = Saisie(chaine2);
                
                printf("\n");
                Recherche_Info(Recherche(chaine, chaine2));
                printf("\n");
                break;
            case 10://Remplacer
                //enter the first string
                printf("Entrez la chaine principale   : ");
                //make sure that the pointer is empty
                chaine = Clear(chaine);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine = Saisie(chaine);

                //enter the second string
                gotoxy(5, wherey());
                printf("Entrez la chaine a rechercher : ");
                //make sure that the pointer is empty
                chaine2 = Clear(chaine2);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine2 = Saisie(chaine2);

                //enter the third string
                gotoxy(5, wherey());
                printf("Entrez la chaine a remplacer  : ");
                //make sure that the pointer is empty
                chaine3 = Clear(chaine3);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine3 = Saisie(chaine3);

                chaine = Remplacer(chaine, chaine2, chaine3);
                gotoxy(5, wherey());
                printf("Bien remplacer\n\n");

                //print the result
                gotoxy(5, wherey());
                printf("Chaine apres la remplacement : ");
                gotoxy(5, wherey()+1);
                printf(" > ");
                Affichage(chaine);
                printf("\n");
                break;
        }
        gotoxy(5, wherey()+1);
        printf("retour au menu");
        getch();
        clrscr();
    }
    return 0;
}

int menu()
{
    int choice;
    int isError;
    int inputPosition;

    Desktop(35, 0);

    do
    {
        rect(25, 17, 6, 8);
        rect(23, 15, 7, 9);

        Title(4, 1);
        puts("      ( Word processing software)\n\n");

        gotoxy(15, wherey());
        puts(" Menu\n");
        gotoxy(12, wherey());
        puts(" 1.Saisie");
        gotoxy(12, wherey());
        puts(" 2.Affichage");
        gotoxy(12, wherey());
        puts(" 3.Longueur");
        gotoxy(12, wherey());
        puts(" 4.Copie");
        gotoxy(12, wherey());
        puts(" 5.Concatenation");
        gotoxy(12, wherey());
        puts(" 6.Inversion");
        gotoxy(12, wherey());
        puts(" 7.Insertion");
        gotoxy(12, wherey());
        puts(" 8.Suppression");
        gotoxy(12, wherey());
        puts(" 9.Recherche");
        gotoxy(12, wherey());
        puts("10.Remplacer");
        gotoxy(12, wherey());
        puts(" 0.Sortir");

        gotoxy(12, wherey());
        printf("  > ");        
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