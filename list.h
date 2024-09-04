#pragma once
typedef struct node node_t;
node_t *newList();
int size(node_t *list);
int get(node_t *list, int index);
void *print(node_t *list);
void add(node_t *list, int e);
void runListExercise();
