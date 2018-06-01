//
// Created by puzankova 30.05.18
//

#include "stack.h"

struct Node {
    double value;
    struct Node *next;
    struct Node *prev;

};

struct Node *stack = NULL; // it is your stack to work with it
int size = 0;

struct Node *newNode() {
    struct Node *new = malloc(sizeof(struct Node));
    new->next = NULL;
    new->prev = NULL;
    new->value = NULL;
    return new;
}

int push(double value) {
    // return the exit code:
    //	0 - success
    //	1 - not enough free space in the stack
    //  2 - other

    // the stack size is 50 elements
    /* YOUR CODE */

    if (size >= 50) {
        return 1;
    }
    struct Node *new = newNode();
    new->value = value;
    if (stack == NULL) {
        stack = new;
    } else {
        new->next = stack;
        new->next->prev = new;
        stack = new;
    }
    size++;
    return 0;
}

double pop() {
    // returns top value and delete it from stack
    // if stack is empty returns -infinity and print error message to the screen
    /* YOUR CODE */


}

double pick() {
    // just returns the top value
    // if stack is empty returns -infinity and print error message to the screen
    /* YOUR CODE */
}