//
// Created by puzankova 30.05.18
//

#include <math.h>
#include "priority_queue.h"

struct Node {
    double value;
    int key;
    struct Node *next;
    struct Node *prev;

};

struct Node *queue = NULL; // it is your queue to work with it
int size = 0;

struct Node *newNode() {
    struct Node *new = malloc(sizeof(struct Node));
    new->next = NULL;
    new->prev = NULL;
    return new;
}

int insert(double value, int key) {
    // return the exit code:
    //	0 - success
    //	1 - not enough free space in the queue
    //  2 - other

    // the queue size is 100 elements

    /* YOUR CODE */

    if (size >= 100) {
        return 1;
    }
    struct Node *new = newNode();
    new->value = value;
    new->key = key;
    if (queue == NULL) {
        queue = new;
    } else {
        struct Node *pointer = queue;
        while (pointer->key <= key && pointer->next != NULL) {
            pointer = pointer->next;
        }
        if (size == 1) {
            if (key >= pointer->key) {
                pointer->next = new;
                new->prev = pointer;
            } else {
                pointer->prev = new;
                new->next = pointer;
                queue = new;
            }
        } else if (pointer->prev == NULL) {
            pointer->prev = new;
            new->next = pointer;
            queue = new;
        } else if (pointer->next == NULL) {
            pointer->next = new;
            new->prev = pointer;
        } else {
            pointer->prev->next = new;
            new->prev = pointer->prev;
            new->next = pointer;
            pointer->prev = new;

        }
    }
    size++;
    return 0;
}

double extract_min() {
    // returns the min value and delete it from queue
    // if queue is empty returns -infinity and print error message to the screen
    /* YOUR CODE */

    if (size <= 0) {
        printf("Queue is empty\n");
        return -INFINITY;
    }
    struct Node *resNode = queue;
    queue = queue->next;
    if (queue != NULL) {
        queue->prev = NULL;
    }
    double res = resNode->value;
    free(resNode);
    size--;
    return res;
}