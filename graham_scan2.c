/***********************************************************************************
 * This file contains the code (i.e. functions) for implementing Graham's Scan 
 * algorithm using heap sort (fast sorting algorithm).
************************************************************************************/
#include <stdio.h>
#include <math.h>
#include <time.h> 
#include "stack.c"
#include "sort2.c"


/**
 * Checks if the turn is clockwise, counter clockwise, or collinear
 * @param a first point
 * @param b second point
 * @param c third point
 * @return -1 (clockwise), 1 (counter clockwise), or 0 (collinear)
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
int isCCW(struct Point a, struct Point b, struct Point c) {
    double turn = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(turn < 0)       
        return -1;      // clockwise
    else if(turn > 0)  
        return 1;       // counter clockwise
    else 
        return 0;       // collinear   
}

/**
 * Finds the point with the lowest y coordinate
 * @param points array of n points
 * @param n number of points
 * @return the point with the lowest y coordinate
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
struct Point findLowestY(struct Point points[], int n) {
    int lowest = 0;
    for(int i = 1; i<n; i++)
        if(points[i].y < points[lowest].y || (points[i].y == points[lowest].y && points[i].x < points[lowest].x))
            lowest = i;

    return points[0];
}

/**
 * Apply Graham's Scan Algorithm on the given set of points using heap sort (fast sorting algorithm)
 * @param points array of n points
 * @param S stack used to store the hull
 * @param n number of points
 * @return the point with the lowest y coordinate
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void grahamScanFastAlgo(struct Point points[], struct Stack *S, int n) {
    // record the start time 
    clock_t start = clock();  

    // find the lowest y coordinate
    struct Point lowestYCoord = findLowestY(points, n);

    // find the angle between the bottom most point and the 
    double angles[MAX];
    for (int i = 0; i < n; i++)
        angles[i] = (atan2(points[i].y - lowestYCoord.y, points[i].x - lowestYCoord.x) * 180 / M_PI);

    // apply fast sorting algorithm
    heapSort(points, angles, n-1);

    // initialize stack and put initial coordinates
    push(S, points[0]);
    push(S, points[1]);
    push(S, points[2]);

    // push remaining points 
    for (int i=3; i<n; i++) {
        while (S->top >= 1 && isCCW(nextToTop(*S), top(*S), points[i]) != 1)
            pop(S);             // pop element(s) if it makes a clockwise turn

        push(S, points[i]);     // push element(s) if it makes a counter clockwise turn
    }

    // end timer
    clock_t end = clock(); 

    // display elapsed time
    printf("------------------------------\n");
    printf("Input Size: %d\n", n);  
    printf("Elapsed Time (ms): %0.6lf\n", (double)(end - start)); 
    printf("------------------------------\n");
}