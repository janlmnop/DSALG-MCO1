/***********************************************************************************
 * This file contains the code (i.e. functions) for implementing heap sort (fast 
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
 * Compares a parent node with its children and ensures the largest angle (relative 
 * to the bottom-most point and the horizontal) is at the top of the heap.
 * @param points array of n points
 * @param angles array of angles
 * @param n number of points
 * @param i index of a point
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void heapify(struct Point points[], double angles[], int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    // Compare angles (largest angle = higher priority)
    if(left < n && angles[left] > angles[largest])
        if(points[left].y > points[largest].y || (points[left].y == points[largest].y && points[left].x > points[largest].x))
            largest = left;
    if(right < n && angles[right] > angles[largest])
        if(points[right].y > points[largest].y || (points[right].y == points[largest].y && points[right].x > points[largest].x))
            largest = right;

    if(largest != i) {
        swap(&points[i], &points[largest]);
        swapAngles(&angles[i], &angles[largest]);
        heapify(points, angles, n, largest);
    }
}


/**
 * Sorts elements by finding the smallest value in the array and swapping it with the first unsorted element
 * @param points array of n points
 * @param angles array of angles
 * @param n number of points
 * 
 * @author: Janelle Ann F. Daguiso
 * @tester: Janelle Ann F. Daguiso
 */
void heapSort(struct Point points[], double angles[], int n) {
    // builds the heap
    for (int i=n/2-1; i>=0; i--)
        heapify(points, angles, n, i);

    // moves elements of the heap
    for (int i=n-1; i>0; i--) {
        swap(&points[0], &points[i]);
        swapAngles(&angles[0], &angles[i]);
        heapify(points, angles, i, 0);
    }
}