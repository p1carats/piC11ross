//
// Created by cyril on 07/04/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define UP 0
#define DOWN 1

// LISTES BILATERES **************************************************

typedef struct DoubleLinkedListElem {
	int data;
	struct DoubleLinkedListElem *previous;
	struct DoubleLinkedListElem *next;
} DoubleLinkedListElem;

typedef struct DoubleLinkedList {
	DoubleLinkedListElem *head;
	int size; // Nombre de maillons
	DoubleLinkedListElem *tail;
} DoubleLinkedList;

// création d'une nouvelle liste chaînée bilatère vide, cette fonction renvoie un pointeur sur la nouvelle structure liste chaînée bilatère vide
DoubleLinkedList *newDoubleLinkedList();

// instanciation (création) d'un élément (maillon) à insérer dans une liste chaînée bilatère avec stockage de la donnée value dans l'élément de liste
DoubleLinkedListElem *newDoubleLinkedListItem(int value);


// affichage des éléments d'une liste chaînée bilatère en commençant par la tête
int displayDoubleList(DoubleLinkedList *liste);
// affichage des éléments d'une liste chaînée bilatère en commençant par la queue (Reverse)
int revDisplayDoubleList(DoubleLinkedList *liste);
// insertion d'un élément en queue de liste chaînée bilatère
int insertItemAtDoubleLinkedListTail(DoubleLinkedList *liste, DoubleLinkedListElem *newItem);
// insertion d'un élément en tête de liste chaînée bilatère
int insertItemAtDoubleLinkedListHead(DoubleLinkedList *liste, DoubleLinkedListElem *newItem);
// insertion d'un élément après un autre élément
int insertItemAfterItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, DoubleLinkedListElem *newItem);
// insertion d'un élément avant un autre élément
int insertItemBeforeItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, DoubleLinkedListElem *newItem);
// insère un nouvel élément contenant "value" en nième position
int insertItemAtIndexIntoLinkedList(DoubleLinkedList *liste, int index, int value);

// renvoie le nombre d'élément contenus dans la liste
int getDoubleLinkedListSize(DoubleLinkedList *liste);
// fonctions qui manipulent la liste en utilisant l'index (no d'ordre dans la liste) des Items
// renvoie EXIT_FAILURE ou NULL s'il n'y a pas d'élément en nième position
// renvoie un pointeur sur le nième élément de la liste
DoubleLinkedListElem *getItemAtIndexFromDoubleLinkedList(DoubleLinkedList *liste, int index);
// obtient la valeur d'un élément
int getValueOfDoubleLinkedListItem(DoubleLinkedListElem *item, int *valeur);
// modifie la valeur d'un élément
int setValueOfDoubleLinkedListItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, int value);
// obtention d'un pointeur sur le prochain élément contenant "value", en partant de l'élément "item" et en
// allant soit vers la tête (UP), soit vers la queue (DOWN)
DoubleLinkedListElem * getNextDoubleLinkedListItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, int value, int sens);

// destruction de tous les éléments d'une liste chaînée
int emptyDoubleLinkedList(DoubleLinkedList *liste);
// suppression et destruction d'un élément de liste chainée
int deleteDoubleLinkedListItem(DoubleLinkedList *liste, DoubleLinkedListElem *item);