#include "functions.h"

// création d'une nouvelle liste chaînée bilatère vide, cette fonction renvoie un pointeur sur la nouvelle structure liste chaînée bilatère vide
DoubleLinkedList *newDoubleLinkedList(){
	DoubleLinkedList *liste = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
	if (liste != NULL){
		liste->size = 0;
		liste->head = NULL;
		liste->tail = NULL;
		return liste;
	}else{
		return NULL;
	}
}

// instanciation (création) d'un élément (maillon) à insérer dans une liste chaînée bilatère avec stockage de la donnée value dans l'élément de liste
DoubleLinkedListElem *newDoubleLinkedListItem(int value, int pos){
	DoubleLinkedListElem *maillon = (DoubleLinkedListElem*) malloc(sizeof(DoubleLinkedListElem));
	if (maillon != NULL){
		maillon->tab[pos] = value;
		maillon->next = NULL;
		maillon->previous = NULL;
		return maillon;
	}else{
		return NULL;
	}
}

// affichage des éléments d'une liste chaînée bilatère en commençant par la tête
int displayDoubleList(DoubleLinkedList *liste){
	DoubleLinkedListElem *elem;
	elem = liste->head;
	int retour = 0; // 0 : tout va bien | -1 : erreur

	if (liste != NULL){
		for (int i = 0; i < liste->size; i++){
			
			for(int s=0; s<10; s++)
			printf("%d) %d\n", i, elem->tab[s]);
			
			elem = elem->next;
		}
		retour = 0;
	}else{
		retour = -1;
	}

	return retour;
}

// affichage des éléments d'une liste chaînée bilatère en commençant par la queue (Reverse)
int revDisplayDoubleList(DoubleLinkedList *liste){
	DoubleLinkedListElem *elem;
	elem = liste->tail;
	int retour = 0; // 0 : tout va bien | -1 : erreur

	if (liste != NULL){
		for (int i = liste->size - 1; i >= 0 ; i--){
			for (int s = 0; s < 10; s++)
				printf("%d) %d\n", i, elem->tab[s]);

			elem = elem->previous;
		}
		retour = 0;
	}else{
		retour = -1;
	}

	return retour;
}


