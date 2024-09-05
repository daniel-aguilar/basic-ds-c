#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct node {
	struct node_t* root;
	int value;
	struct link_t* children;
} node_t;

typedef struct link {
	struct node_t* value;
	struct link_t* next;
} link_t;

link_t* makeLink(void) {
	link_t* newLink = malloc(sizeof(link_t));
	newLink->value = NULL;
	newLink->next = NULL;
	return newLink;
}

void addLink(const link_t* list, node_t* node) {
	link_t* newLink = makeLink();
	newLink->value = node;

	link_t* head = list;
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = newLink;
}

node_t* makeNode(int n) {
	node_t* node = malloc(sizeof(node_t));
	node->root = NULL;
	node->value = n;
	node->children = makeLink();
	return node;
}

void addChild(const node_t* tree, int n) {
	node_t* leaf = makeNode(n);
	leaf->root = tree;
	addLink(tree->children, leaf);
}

void forEach(const link_t* list, void (*callback)(node_t* node)) {
	link_t* head = list;
	while (head->next != NULL) {
		head = head->next;
		callback(head->value);
	}
}

void printNode(const node_t* node) {
	int value = node->value;

	if (node->root != NULL) {
		printf("Node: %d\n", value);
	}
	else {
		printf("Root: %d\n", value);
	}

	forEach(node->children, printNode);
}

void runTreeExercise(void) {
	node_t* tree = makeNode(1);
	addChild(tree, 2);
	addChild(tree, 3);
	printNode(tree);
}