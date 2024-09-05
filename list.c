#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

struct node {
	int value;
	struct node_t *next;
};

node_t *newList() {
	node_t *list = malloc(sizeof(node_t));
	list->value = NULL;
	list->next = NULL;
	return list;
}

int size(node_t *list) {
	int size = 0;
	node_t *head = list;
	
	while (head->next != NULL) {
		head = head->next;
		size++;
	}
	return size;
}

int get(node_t *list, int index) {
	if (index + 1 > size(list)) {
		printf("WARN: Index out of bounds\n");
		return NULL;
	}

	node_t *head = list;
	for (int i = 0; i <= index; i++) {
		head = head->next;
	}
	return head->value;
}

char* toString(node_t* list) {
	node_t* head = list;
	char* result = malloc(1 + 1);
	strcpy(result, "[");

	while (head->next != NULL) {
		head = head->next;

		char str[3];
		sprintf(str, "%d", head->value);

		int len = strlen(result) + strlen(str);
		result = realloc(result, len + 1);
		strcat(result, str);

		result = realloc(result, strlen(result) + 2 + 1);
		if (head->next != NULL) {
			strcat(result, ", ");
		}
		else {
			strcat(result, "]");
		}
	}

	return result;
}

void add(node_t *list, int e) {
	node_t *head = list;

	while (head->next != NULL) {
		head = head->next;
	}

	node_t *newItem = malloc(sizeof(node_t));
	newItem->value = e;
	newItem->next = NULL;
	head->next = newItem;
}

void runListExercise() {
	node_t* myList = newList();
	add(myList, 1);
	add(myList, 2);
	add(myList, 3);

	printf("Size: %d\n", size(myList));
	printf("Item: %d\n", get(myList, 0));
	printf("Item: %d\n", get(myList, 1));
	printf("Item: %d\n", get(myList, 2));
	printf("Item: %d\n", get(myList, 3));

	printf("List: %s\n", toString(myList));
}
