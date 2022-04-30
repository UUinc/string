#ifndef CHAINE_H
#define CHAINE_H

#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

typedef struct node
{
    char value;
    struct node *next; 
    struct node *prev; 
}node;

//1.	Saisie : création d’une chaîne de caractères à partir de la saisie d’un utilisateur.
node* CreateNode(char _value)
{
    node* _node = (node*) malloc(sizeof(node));

    _node->value = _value;

    _node->next = _node->prev = NULL;
}
node* AddAtEnd(node* head, node* newNode)
{
    node *p = head;

    if(head == NULL)
    {
        head = CreateNode('~');

        newNode->next = head;
        head->next = newNode;

        newNode->prev = head;
        head->prev = newNode;

        return head;
    }
    //iterate to the last node in the list
    while(p->next != head)
    {
        p = p->next;
    }
    //add the new node
    //change links in the header and last item
    p->next->prev = newNode;
    p->next = newNode;
    //change links for the new node
    newNode->next = head;
    newNode->prev = p;

    return head;
}
char GetKey() 
{
    int key;
    if (kbhit()) 
    {
        key=getch();
        if (key == 0) 
        {
            do 
            {
                key=getch();
            } while(key==0);

            switch (key)
            {
                case 72:
                    //up
                    break;
                case 75:
                    //left
                    printf("\033[1D"); // Move left X column;
                    break;
                case 77:
                    //right
                    printf("\033[1C"); // Move right X column;
                    break;
                case 80:
                    //down
                    break;
                case 83:
                    //delete
                    clear();
                    break;
            }
            return 0;
        }
        return key;
    }
    return 0;
}
node* Saisie(node* head)
{
    char c;

    do
    {
        c = GetKey();

        if(c == 8)
        {
            printf("\b \b");
        }

        if(c == 9 || (c >= 32 && c <= 126))
        {
            putchar(c);

            //store character in a linked list
            head = AddAtEnd(head, CreateNode(c));
        }
    }while(c != '\r');
    putchar('\n');

    return head;
}

//2.	Affichage : affichage d’une chaîne de caractère stockée en mémoire.
void Affichage(node* head)
{
    node *p = head;

    if(head == NULL)
    {
        printf("");
    }

    while(p->next != head)
    {
        if(p != head)
            putchar(p->value);

        p = p->next;
    }
}

//3.	Longueur : renvoi de la longueur d’une chaîne de caractères.

//4.	Copie : création de la copie d’une chaîne de caractères à partir d’une chaîne déjà existante.

//5.	Concaténation : création d’une nouvelle chaîne de caractères égale à la concaténation de deux chaînes existantes 
//(Les 2 chaînes de base ne doivent pas être modifiées !).

//6.	Inversion : inversion d’une chaîne de caractères déjà existante.

//7.	Insertion : insertion d’une chaîne de caractères dans une autre chaîne caractères à une position choisie par l’utilisateur.

//8.	Suppression : suppression d’un certain nombre de caractères, choisi par l’utilisateur, 
//dans une chaîne à partir d’une position choisie par l’utilisateur.

//9.	Recherche : recherche dans une chaîne de caractères toutes les occurrences d’une sous- chaîne donnée 
//en renvoyant toutes les positions de cette dernière le cas échéant.

//10.	Remplacer : remplacement dans une chaîne de caractères de toutes les occurrences d’une sous-chaîne 
//donnée par une autre sous-chaîne donnée.


#endif