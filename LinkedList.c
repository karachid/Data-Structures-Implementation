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

/*
 * insert : It inserts a new item in the list after a given item,
 * or at the end of the list if the given item does not exist
 * @h : head of the list
 * @newVal : new item to insert
 * @x : the item following which we insert
 */
void insert(Node* h, int newVal, int x){
	Node *head = h, *newNode, *p;
	newNode = malloc(sizeof(struct Node));
	newNode->value = newVal;

	while(h && h->value != x){
		p = h;
		h = h->next;
	}

	if(h){
		newNode->next = h->next;
		h->next = newNode;
	}
	else {
		p->next = newNode;
		newNode->next = NULL;	
	}
}

/*
 * front : It returns the first value in a list
 * @h : head of the list
 * Return: integer that represents the first value in the list
 */
int front(Node* h){
	if(h != NULL)
		return h->value;

	return EXIT_FAILURE; 	
}

/*
 * back : It returns the last value in the list
 * @h : head of the list
 * Return: integer that represents that last value in the list
 */
int back(Node* h){
	if(h != NULL){
		while(h->next != NULL){
			h = h->next;
		}
		return h->value;
	}
	return EXIT_FAILURE;
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
