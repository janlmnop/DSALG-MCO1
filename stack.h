/***********************************************************************************
 * This file contains the definitions, structures, and function prototypes used in
 * stack implementation
************************************************************************************/

#define MAX 32768   // maximum array elements
#define TRUE 1      // sets 1 as true
#define FALSE 0     // sets 0 as false


/**
 * Represents a stack
*/
struct Stack {
    double S[MAX];      // array of maximum 2^15 elements
    int top;            // index of top
};