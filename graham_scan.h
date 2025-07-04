/***********************************************************************************
 * This file contains the definitions, structures, and function prototypes used in
 * Graham's Scan algorithm using a Heap Sort (fast soting algorithm).
************************************************************************************/

#ifndef graham_scan
#define graham_scan

#define MAX 32768   // maximum array elements
#define TRUE 1      // sets 1 as true
#define FALSE 0     // sets 0 as false

typedef char String[31];

struct Point {
    double x;       // x coordinate
    double y;       // y coordinate
};

struct Stack {
    struct Point points[MAX];      // array of maximum 2^15 elements
    int top;                       // index of top
};

#endif