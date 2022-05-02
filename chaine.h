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

//Functions Prototype
//linked list functions
node* CreateNode(char);
node* Add(node*, node*, int);
node* AddAtStart(node*, node*);
node* AddAtEnd(node*, node*);
char GetCharFromList(node*, int);
//Program functions
node* Saisie(node*);
void Affichage(node*);
int Longueuer(node*);
node* Copie(node*);
node* Concatenation(node*, node*);
node* Inversion(node*);
node* Insertion(node*, node*, int);
node* Suppression(node*, int, int);
void Recherche(node*, node*);

//0.    LinkedList functions
node* CreateNode(char _value)
{
    node* _node = (node*) malloc(sizeof(node));

    _node->value = _value;

    _node->next = _node->prev = NULL;
}
//optimize this shitty code you idiot -_-
node* Add(node* head, node* newNode, int position)
{
    int counter=0;
    node *p = head;

    if(head == NULL)
    {
        head = newNode;

        head->next = head;
        head->prev = head;

        return head;
    }

    //Add at Start
    if(position <= 1)
    {
        newNode->next = head;
        newNode->prev = head->prev;

        head->prev->next = newNode;
        head->prev = newNode;
        
        head = newNode;

        return head;
    }

    //Add at End
    if(position > Longueuer(head))
    {
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

    //At position
    //iterate to the last node in the list
    while(p->next != head)
    {
        counter++;
        if(counter == position)
        {
            break;
        }

        p = p->next;
    }
    //add the new node
    //change links in the header and last item
    newNode->prev = p->prev;
    newNode->next = p;

    p->prev->next = newNode;
    p->prev = newNode;

    return head;
}
node* AddAtStart(node* head, node* newNode)
{
    Add(head, newNode, 0);
}
node* AddAtEnd(node* head, node* newNode)
{
    Add(head, newNode, Longueuer(head) + 1);
}
char GetCharFromList(node* head, int index)
{
    node* p = head;
    int counter = 0;

    while(p->next != head)
    {
        if(counter == index)
        {
            return p->value;
        }

        p = p->next;
        counter++;
    }
    if(counter == index)
    {
        return p->value;
    }

    puts("Erreur index out of range");
    return '\0';
}
//1.	Saisie : création d’une chaîne de caractères à partir de la saisie d’un utilisateur.
node* Saisie(node* head)
{
    char c;

    do  
    {  
        c = getchar();

        if(c == '\n' || c == EOF)
            break;

        //store character in a linked list
        head = AddAtEnd(head, CreateNode(c)); 
    } while (1);

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
    putchar(p->value);
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
    len++;

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
node* Concatenation(node* str1, node* str2)
{
    node *p = str2;
    node *str3 = NULL;

    str3 = Copie(str1);

    if(str2 == NULL)
    {
        return str3;
    }

    while(p->next != str2)
    {
        //store character in a the new linked list
        str3 = AddAtEnd(str3, CreateNode(p->value));
        p = p->next;
    }
    //store the last character in a the new linked list
    str3 = AddAtEnd(str3, CreateNode(p->value));

    return str3;
}

//6.	Inversion : inversion d’une chaîne de caractères déjà existante.
node* Inversion(node* head)
{
    node* p = head;

    node* newHead = head->prev;
    node* tempNext;

    if(head == NULL)
    {
        return NULL;
    }

    while(p->next != head)
    {
        //swap next with prev
        tempNext = p->next;
        p->next = p->prev;
        p->prev = tempNext;

        p = tempNext;
    }
    //swap next with prev
    tempNext = p->next;
    p->next = p->prev;
    p->prev = tempNext;

    head = newHead;
    return head;
}
//7.	Insertion : insertion d’une chaîne de caractères dans une autre chaîne caractères à une position choisie par l’utilisateur.
node* Insertion(node* head, node* str, int position)
{
    node* p = str;

    if(str == NULL)
    {
        return head;
    }

    if(head == NULL)
    {
        head = Copie(str);
        return head;
    }

    while(p->next != str)
    {
        head = Add(head, CreateNode(p->value), position);
        position++;
        p = p->next;
    }
    head = Add(head, CreateNode(p->value), position);

    return head;
}
//8.	Suppression : suppression d’un certain nombre de caractères, choisi par l’utilisateur, 
//dans une chaîne à partir d’une position choisie par l’utilisateur.
node* Suppression(node* head, int position, int length)
{
    node* p = head;
    node* tempNext;
    int count = 0;

    if(head == NULL)
    {
        return head;
    }

    while(p->next != head)
    {
        count++;
        tempNext = p->next;

        if(count >= position && count < position + length)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
        }
        p = tempNext;
    }

    return head;
}
//9.	Recherche : recherche dans une chaîne de caractères toutes les occurrences d’une sous- chaîne donnée 
//en renvoyant toutes les positions de cette dernière le cas échéant.
void Recherche(node* head, node* str)
{
    int i, j, k;
    int head_len = Longueuer(head);
    int str_len = Longueuer(str);

    int position = -1;
    int found = 0;

    if(head == NULL || str == NULL)
    {
        printf("la chaine est vide");
        return;
    }

    if(head_len < str_len)
    {
        printf("Aucune occurence a ete trouve");
        return;
    }

    for(i=0; i <head_len; i++)
    {
        for(j=0, k=i; j<str_len; j++)
        {
            if(GetCharFromList(head, k) != GetCharFromList(str, j))
            {
                position = -1;
                break;
            }

            if(position == -1)
            {
                position = k;
            }

            k++;
            if(k >= head_len)
            {
                j++;
                //break from the main loop
                i = head_len;
                break;
            }
        }
        if(j == str_len)
        {
            found++;
            printf("Occurence n\xF8%d = %d\n", found, position + 1);

            //reset positon for the next occurence;
            position = -1;
        }
    }

    if(found == 0)
    {
        printf("Aucune occurence a ete trouve");
        return;
    }
}
//10.	Remplacer : remplacement dans une chaîne de caractères de toutes les occurrences d’une sous-chaîne 
//donnée par une autre sous-chaîne donnée.


#endif