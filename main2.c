/***********************************************************************************
 * This file is the driver program to compute for the convex hull of a set of 
 * coordinates using Graham's Scan algorithm (fast sorting algorithm). It reads 
 * entries from a text file, computes for the convex hull, and outputs a text
 * file containing the coordinates of the convex hull.
************************************************************************************/
#include <stdio.h>
#include "graham_scan2.c"
#include "graham_scan.h"


// driver
int main() {
    FILE *fp;
    String infilename;
    String outfilename;
    int i=0, j;
    int n;                          // input / problem size
    struct Point points[MAX];
    struct Stack S;
    create(&S);

    printf("Enter the input filename and extension: ");
    scanf("%s", infilename);

    printf("Enter the output filename and extension: ");
    scanf("%s", outfilename);

    // read input file
    fp = fopen(infilename, "r");
    if ((fp = fopen(infilename, "r")) == NULL)
        fprintf(stderr, "Error %s does not exist.\n", infilename);

    // read the first line -> input size
    fscanf(fp, "%d", &n);
    while(fscanf(fp, "%lf    %lf\n", &points[i].x, &points[i].y) == 2)
        i++;
    
    // apply Graham's Scan algorithm using heap sort
    grahamScanFastAlgo(points, &S, n);

    // print to file (with the correct format)
    fp = fopen(outfilename, "w");
    fprintf(fp, "%d\n", S.top+1);
    for(j=0; j<S.top+1; j++)
        fprintf(fp, "%9.6lf%11.6lf\n", S.points[j].x, S.points[j].y);


    fclose(fp);

    return 0;
}