#ifndef CHAINE_H
#define CHAINE_H

#include <stdio.h>
#include <stdlib.h>

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
        head = newNode;

        head->next = head;
        head->prev = head;

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
node* Saisie(node* head)
{
    char c;

    do  
    {  
        c = getchar();
        //store character in a linked list
        head = AddAtEnd(head, CreateNode(c)); 
    } while (c != '\n');

    return head;
}

//2.	Affichage : affichage d’une chaîne de caractère stockée en mémoire.
void Affichage(node* head)
{
    node *p = head;

    if(head == NULL)
    {
        printf("");
        return;
    }

    while(p->next != head)
    {
        putchar(p->value);
        p = p->next;
    }
}

//3.	Longueur : renvoi de la longueur d’une chaîne de caractères.
int Longueuer(node* head)
{
    int len = 0;
    node *p = head;

    if(head == NULL)
    {
        return 0;
    }

    while(p->next != head)
    {
        len++;
        p = p->next;
    }
    return len;
}
//4.	Copie : création de la copie d’une chaîne de caractères à partir d’une chaîne déjà existante.
node* Copie(node* head)
{
    node *p = head;
    node *newNode = NULL;

    if(head == NULL)
    {
        return NULL;
    }

    while(p->next != head)
    {
        //store character in a the new linked list
        newNode = AddAtEnd(newNode, CreateNode(p->value));
        p = p->next;
    }
    //store the last character in a the new linked list
    newNode = AddAtEnd(newNode, CreateNode(p->value));

    return newNode;
}
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