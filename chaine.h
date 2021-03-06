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
char GetCharByIndex(node*, int);
node* Clear(node*);
//Program functions
node* Saisie(node*);
void Affichage(node*);
int Longueuer(node*);
node* Copie(node*);
node* Concatenation(node*, node*);
node* Inversion(node*);
node* Insertion(node*, node*, int);
node* Suppression(node*, int, int);
int* Recherche(node*, node*);
node* Remplacer(node*, node*, node*);
//Tools function
void Recherche_Info(int*);

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
    return Add(head, newNode, 0);
}
node* AddAtEnd(node* head, node* newNode)
{
    return Add(head, newNode, Longueuer(head) + 1);
}
char GetCharByIndex(node* head, int index)
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
node* Clear(node* head)
{
    node* p;
    node* tmpP;

    if(head == NULL)
        return NULL;

    p = head->prev;
    while(p != head)
    {
        tmpP = p->prev;
        free(p);
        p = tmpP;
    }
    free(p);
    head = NULL;
    return head;
}
//1.	Saisie : cr??ation d???une cha??ne de caract??res ?? partir de la saisie d???un utilisateur.
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

//2.	Affichage : affichage d???une cha??ne de caract??re stock??e en m??moire.
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

//3.	Longueur : renvoi de la longueur d???une cha??ne de caract??res.
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
//4.	Copie : cr??ation de la copie d???une cha??ne de caract??res ?? partir d???une cha??ne d??j?? existante.
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
//5.	Concat??nation : cr??ation d???une nouvelle cha??ne de caract??res ??gale ?? la concat??nation de deux cha??nes existantes 
//(Les 2 cha??nes de base ne doivent pas ??tre modifi??es !).
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

//6.	Inversion : inversion d???une cha??ne de caract??res d??j?? existante.
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
//7.	Insertion : insertion d???une cha??ne de caract??res dans une autre cha??ne caract??res ?? une position choisie par l???utilisateur.
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
//8.	Suppression : suppression d???un certain nombre de caract??res, choisi par l???utilisateur, 
//dans une cha??ne ?? partir d???une position choisie par l???utilisateur.
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
            p->next->prev = p->prev;
            p->prev->next = p->next;

            if(p == head)
            {
                head = p->next;
            }

            free(p);
        }
        p = tempNext;
    }
    count++;
    if(count >= position && count < position + length)
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;

        if(p == head)
        {
            head = p->next;
        }

        free(p);
    }
    return head;
}
//9.	Recherche : recherche dans une cha??ne de caract??res toutes les occurrences d???une sous- cha??ne donn??e 
//en renvoyant toutes les positions de cette derni??re le cas ??ch??ant.
int* Recherche(node* head, node* str)
{
    int i, j, k;
    int head_len = Longueuer(head);
    int str_len = Longueuer(str);

    int position = -1;
    int found = 0;

    //dynamic array
    int *positions = (int*) malloc(sizeof(int));
    *positions = 0;

    if(head == NULL || str == NULL)
    {
        return positions;
    }

    if(head_len < str_len)
    {
        return positions;
    }

    for(i=0; i <head_len; i++)
    {
        for(j=0, k=i; j<str_len; j++)
        {
            if(GetCharByIndex(head, k) != GetCharByIndex(str, j))
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
            *positions = found;

            positions = (int*) realloc(positions, (found + 1) * sizeof(int));
            *(positions + found) = position + 1;
            
            //reset positon for the next occurence;
            position = -1;
        }
    }

    //the length of the array is the first value
    return positions;
}
//10.	Remplacer : remplacement dans une cha??ne de caract??res de toutes les occurrences d???une sous-cha??ne 
//donn??e par une autre sous-cha??ne donn??e.
node* Remplacer(node* str, node* strFind, node* strReplace)
{
    int i;

    int strFindLen = Longueuer(strFind);
    int strReplaceLen = Longueuer(strReplace);
    int diffPosition = strReplaceLen - strFindLen;

    int *rechercheResultat = Recherche(str, strFind);

    if(str == NULL || strFind == NULL || strReplace == NULL)
    {
        return str;
    }

    //Update recherche data
    //the first value in the array is the size of the array
    for(i = 1; i <= *rechercheResultat; i++)
    {
        *(rechercheResultat + i) += (diffPosition * (i - 1));
    }
    
    //Replace algorithm
    for(i = 1; i <= *rechercheResultat; i++)
    {
        str = Suppression(str, *(rechercheResultat + i), strFindLen);
        str = Insertion(str, strReplace, *(rechercheResultat + i));
    }
    return str;
}

//Tools functions
void Recherche_Info(int* data)
{
    if(*data == 0)
    {
        gotoxy(5, wherey());
        printf("Aucune occurrence n'a ete trouvee\n");
        return;
    }

    for(int i=1; i<= *data; i++)
    {
        gotoxy(5, wherey());
        printf("Occurence n\xF8%d = %d\n", i, *(data+i));
    }
}
#endif