/***********************************************************************************
 * This file contains the code (i.e. functions) for implementing selection sort (slow 
 * sorting algorithm).
************************************************************************************/
#include <stdio.h>
#include "graham_scan.h"


/**
 * Swaps points in an array of points
 * @param a first point
 * @param b second point
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void swap(struct Point *a, struct Point *b) {
    struct Point temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Swaps angles in array of double data types
 * @param a first angle
 * @param b second angle
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void swapAngles(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 
 * @param points array of n points
 * @param angles array of angles
 * @param n number of points
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void selectionSort(struct Point points[], double angles[], int n) {
    int i, j, minIndex;

    for(i=0; i<n-1; i++) {
        minIndex = i;
        for(j=i+1; j<n; j++) {
            if(angles[j] < angles[minIndex])
                minIndex = j;
        } 
        swap(&points[minIndex], &points[i]);
        swapAngles(&angles[minIndex], &angles[i]);
    }
}