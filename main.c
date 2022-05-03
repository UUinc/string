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
                printf("Bien copier\n\n");
                
                //print the result
                printf("Chaine principale : \n > ");
                Affichage(chaine);
                printf("\n");

                printf("Chaine n\xF8""2     : \n > ");
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
                printf("Entrez la chaine n\xF8""2     : ");
                //make sure that the pointer is empty
                chaine2 = Clear(chaine2);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine2 = Saisie(chaine2);

                chaine = Concatenation(chaine, chaine2);
                printf("Bien concatene\n\n");

                //print the result
                printf("Chaine concatene : \n > ");
                Affichage(chaine);
                printf("\n");
                break;
            case 6://Inversion
                chaine = Inversion(chaine);
                printf("Bien inverser\n\n");

                //print the result
                printf("Chaine inverser : \n > ");
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
                printf("Entrez la chaine a inserer  : ");
                //make sure that the pointer is empty
                chaine2 = Clear(chaine2);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine2 = Saisie(chaine2);

                printf("Donner la position a inserer : ");
                scanf("%d", &position);
                chaine = Insertion(chaine, chaine2, position);
                printf("Bien inserer\n\n");

                //print the result
                printf("Chaine apres l'insertion : \n > ");
                Affichage(chaine);
                printf("\n");
                break;
            case 8://Suppression
                printf("Donner la position a supprimer : ");
                scanf("%d", &position);
                printf("Donner la taille : ");
                scanf("%d", &taille);
                chaine = Suppression(chaine, position, taille);
                printf("Bien supprimer\n\n");

                //print the result
                printf("Chaine apres la suppression : \n > ");
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
                printf("Entrez la chaine a rechercher : ");
                //make sure that the pointer is empty
                chaine2 = Clear(chaine2);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine2 = Saisie(chaine2);

                //enter the third string
                printf("Entrez la chaine a remplacer  : ");
                //make sure that the pointer is empty
                chaine3 = Clear(chaine3);
                //flush the stdin file from unwanted characters
                fflush(stdin);
                chaine3 = Saisie(chaine3);

                chaine = Remplacer(chaine, chaine2, chaine3);
                printf("Bien remplacer\n\n");

                //print the result
                printf("Chaine apres la remplacement : \n > ");
                Affichage(chaine);
                printf("\n");
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