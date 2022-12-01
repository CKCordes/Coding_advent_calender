#include <assert.h> /* assert */
#include <stdbool.h>
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
} linked_list;

node_t *createNode(int value) {
    node_t *nodePtr = malloc(sizeof(node_t));
    nodePtr->data = value;
    nodePtr->next = NULL;
    return nodePtr;
}

linked_list *createLinkedList() {
    linked_list *llPtr = malloc(sizeof(linked_list));
    llPtr->head = NULL;
    return llPtr;
}

void insertFront(node_t *nodePtr, linked_list *llPtr) {
    nodePtr->next = llPtr->head;
    llPtr->head = nodePtr;
}

void printLL(linked_list *llPtr) {
    node_t *n = llPtr->head;
    while (n != NULL) {
        printf("given calorie: %d\n", n->data);
        n = n->next;
    }
}
void freeLL(linked_list *LLptr) {
    node_t *temp = LLptr->head;
    node_t *next = LLptr->head->next;
    while (next != NULL) {
        free(temp);
        temp = next;
        next = next->next;
    }
}

int main() {
    // filepointer
    FILE *calories;

    int givenCalorie;
    int index = 0;
    int finalIndex = 0;

    // LL variables
    linked_list *LLptr = createLinkedList();
    node_t *currNode = LLptr->head;
    node_t *trav;

    int maxCal = 0;
    int tempCal = 0;
    // variuables for file opening
    char *line = NULL;
    size_t len = 0;
    calories = fopen("calories.txt", "r");

    if (calories == NULL) {
        printf("Filen kan ikke åbnes");
        return 1;
    }
    // loading data into linked list, loading line by line, then converting to
    // int to later calculate
    while (getline(&line, &len, calories) != -1) {
        givenCalorie = atoi(line);
        insertFront(createNode(givenCalorie), LLptr);
    }
    // traversing through LL.
    trav = LLptr->head;
    while (trav != NULL) {
        if (trav->data != 0) {
            tempCal += trav->data;
        }
        if (tempCal > maxCal) {
            maxCal = tempCal;
            finalIndex = index;
        }
        if (trav->data == 0) {
            tempCal = 0;
            index++;
        }
        trav = trav->next;
    }
    printf("max calorie: %d\n", maxCal);
    printf("elf index: %d", finalIndex);
    // printLL(LLptr);
    fclose(calories);
    freeLL(LLptr);
    return 0;
}