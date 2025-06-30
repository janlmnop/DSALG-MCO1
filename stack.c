/***********************************************************************************
 * This file contains the code (i.e. functions) for implementing a stack data 
 * structure.
************************************************************************************/
#include <stdio.h>
#include "stack.h"


/**
 * Creates an empty stack and sets top as -1
 * @param S Stack structure
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void create(struct Stack *S) {
    S->top = -1;
}

/**
 * Checks if stack is full
 * @param S Stack structure
 * @return 1 / TRUE if full or 0 / FALSE otherwise
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
int isFull(struct Stack S) {
    if (S.top == MAX-1)
        return TRUE;
    else
        return FALSE;
}

/**
 * Checks if stack is empty
 * @param S Stack structure
 * @return 1 / TRUE if empty or 0 / FALSE otherwise
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
int isEmpty(struct Stack S) {
    if (S.top == -1)
        return TRUE;
    else
        return FALSE;
}

/**
 * Inserts an element into the stack
 * @param S Stack structure
 * @param x Element to be inserted
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void push(struct Stack *S, double x) {
    if((!isFull(*S)) == TRUE) {
        S->top++;
        S->S[S->top] = x; 
    }
    else 
        printf("Stack full!");
}

/**
 * Removes the top most element from the stack
 * @param S Stack structure
 * @return the value of the top most element from the stack
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
double pop(struct Stack *S) {
    if ((!isEmpty(*S)) == TRUE) {
        return S->S[S->top--];
    }
    else {
        printf("Stack empty!");
        return -1;
    }
}

/**
 * Returns the value of the top most element
 * @param S Stack structure
 * @return the value of the top most element from the stack
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
double top(struct Stack S) {
    return S.S[S.top];
}

/**
 * Returns the value below the top most element
 * @param S Stack structure
 * @return the value of the element below the top element
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
double nextToTop(struct Stack S) {
    return S.S[S.top-1];
}

/**
 * Display stack elements
 * @param S Stack structure
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void displayStack(struct Stack *S) {
    for(int i=0; i<S->top+1; i++)
        printf("%0.6f\n", S->S[i]);
}


