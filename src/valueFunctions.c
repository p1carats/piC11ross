//
// Created by cyril on 07/04/2021.
//

#include <stdbool.h>
#include "functions.h"

// renvoie le nombre d'élément contenus dans la liste
int getDoubleLinkedListSize(DoubleLinkedList *liste){
	int retour = -1;

	if (liste != NULL){
		retour = liste->size;
	} 
	return retour;
}

// fonctions qui manipulent la liste en utilisant l'index (no d'ordre dans la liste) des Items
// renvoie EXIT_FAILURE ou NULL s'il n'y a pas d'élément en nième position
// renvoie un pointeur sur le nième élément de la liste
DoubleLinkedListElem *getItemAtIndexFromDoubleLinkedList(DoubleLinkedList *liste, int index){
	DoubleLinkedListElem *retour = NULL;
	if (liste != NULL && liste->size >= index){

		int rang = 0;
		DoubleLinkedListElem *tmp;
		tmp = liste->head;

		while (rang != index){
			tmp = tmp->next;
			rang++;
		}

		retour = tmp;
	}

	return retour;
}

// obtient la valeur d'un élément
int getValueOfDoubleLinkedListItem(DoubleLinkedListElem *item, int *valeur){


	*valeur = item->tab;

	return 0;

}

// obtention d'un pointeur sur le prochain élément contenant "value", en partant de l'élément "item" et en
// allant soit vers la tête (UP), soit vers la queue (DOWN)
DoubleLinkedListElem *getNextDoubleLinkedListItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, int value, int sens){
	DoubleLinkedListElem *retour = NULL;

	if (liste != NULL && item != NULL){ // Si tout existe

		if(sens == UP){

			bool continuer = true;

			if(liste->head == item){ // Si l'élément est en tête
				if(item->tab == value){
					retour = item;
				}else{
					retour = NULL;
				}
			}else{
				while(item != liste->head && continuer){
					if(item->tab == value){
						retour = item;
						continuer =false;
					}
					item = item->previous;
				}

				if (continuer){
					retour = NULL;
				}
			}

		}else if(sens == DOWN){

			bool continuer = true;

			if(liste->tail == item){ // Si l'élément est en queue
				if(item->tab == value){
					retour = item;
				}else{
					retour = NULL;
				}
			}else{
				while(item != liste->tail && continuer){
					if(item->tab == value){
						retour = item;
						continuer = false;
					}
					item = item->next;
				}

				if (continuer){
					retour = NULL;
				}
			}

		}else{ // Dans le cas ou le sens n'est pas defini !
			retour = NULL;
		}

	}else{
		retour = NULL;
	}

	return retour;
}

// modifie la valeur d'un élément
int setValueOfDoubleLinkedListItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, int value){
	int retour = 0;

	if (liste != NULL && item != NULL){

		item->tab = value;

	}else{
		retour = -1;
	}

	return retour;
}