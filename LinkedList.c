#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

Node* createList(int size){
	Node *h = NULL, *tmp = NULL;
	
	for(int i=0; i<size; i++){
		tmp = malloc(sizeof(struct Node));
		tmp->value = i;
		tmp->next = h;
		h = tmp;
	}
	return h;
}

//O(1)
void push_front(Node** h, int newVal){
	Node* newNode = malloc(sizeof(struct Node));
	newNode->value = newVal;
	newNode->next = *h;
	*h = newNode;
}

// 1 + 1 + n ==> O(n)
void push_back(Node* h, int newVal){

	//O(n)
	while(h->next != NULL){
		h = h->next;
	}
	//O(1)
	h->next = malloc(sizeof(struct Node));
	//O(1)
	h->next->value = newVal;
}

//O(n)
void insert(Node* h, int newVal, int x){
	// TODO	
}

void displayList(Node* h){

	while(h != NULL){
		printf("%d\t", h->value);
		h = h->next;
	}
	printf("\n");
}

int getSize(Node* h){
	int s = 0;

	while(h){
		s++;
		h = h->next;
	}

	return s;
}
