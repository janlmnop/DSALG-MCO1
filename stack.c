/***********************************************************************************
 * This file contains the code (i.e. functions) for implementing a stack data 
 * structure.
************************************************************************************/
#include <stdio.h>
#include "graham_scan2.h"


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
    if(S.top == MAX-1)
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
    if(S.top == -1)
        return TRUE;
    else
        return FALSE;
}

/**
 * Inserts a point into the stack
 * @param S Stack structure
 * @param point point to be inserted
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void push(struct Stack *S, struct Point point) {
    if((!isFull(*S)) == TRUE) {
        S->top++;
        S->points[S->top].x = point.x;
        S->points[S->top].y = point.y;
    }
    else 
        printf("Stack full!");
}

/**
 * Removes the top most point from the stack
 * @param S Stack structure
 * @return the coordinates of the top most point from the stack
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
struct Point pop(struct Stack *S) {
    if((!isEmpty(*S)) == TRUE) {
        return S->points[S->top--];
    }
    else {
        printf("Stack empty!");
        return  S->points[0];
    }
}

/**
 * Returns the coordinates of the top most point
 * @param S Stack structure
 * @return the coordinates of the top most point from the stack
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
struct Point top(struct Stack S) {
    return S.points[S.top];
}

/**
 * Returns the point below the top most point
 * @param S Stack structure
 * @return the value of the element below the top element
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
struct Point nextToTop(struct Stack S) {
    return S.points[S.top-1];
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
        printf("%9.6lf%11.6lf\n", S->points[i].x, S->points[i].y);
}


