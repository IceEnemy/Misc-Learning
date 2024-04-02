/* Exercise 7.08: k'th smallest in array
 
Scaffold by Alistair Moffat, August 2013
(c) University of Melbourne */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//#include "arrayops.h"  // includes read_int_array, print_int_array

/* maximum array size allowed */
#define MAXVALS 1000

/* array operations
 * Alistair Moffat, PPSAA, Chapter 7, December 2012
 * (c) University of Melbourne */

/* ****
 * These functions are very slightly modified from insertionsort.c in Figure 7.4
 * Fig 7.4 on pg107 in PPSAA by Alistair Moffat, updating style and comments.
 * **** */

/* sorts n elements of array A in increasing order (2, 3, 4, 5)
 * using insertion sort (insertionsort.c, Figure 7.4 PPSAA) */
 
int sortedArr[MAXVALS];
 
void int_swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void sort_int_array(int A[], int n) {
    /* assume that A[0] to A[n-1] have valid values */
	int i;
	int j;
    for (i = 1; i < n; i++) {
        /* swap A[i] left into correct position (increasing order). */
        for (j = i - 1; j >= 0 && A[j] > A[j + 1]; j--) {
            /* not there yet */
            
            int_swap(&A[j], &A[j + 1]);
        }
    }
}

/* exchange the values of the two variables indicated
 * by the arguments (insertionsort.c, Figure 7.4 PPSAA) */


/* read integers from input and store them in an array.
 * maxvals is the maximum number of elements that can be read in to the array,
 * all other values are discarded
 * returns the number of elements successfully read in
 * (insertionsort.c, Figure 7.4 PPSAA) */
int read_int_array(int A[], int maxvals) {
    int n = 0, excess = 0, next;

    printf("Enter as many as %d values, ^D to end\n", maxvals);
    while (scanf("%d", &next) == 1) {
        if (n == maxvals) {
            excess += 1;
        } else {
            A[n] = next;
            n += 1;
        }
    }

    printf("%d values read into array", n);
    if (excess) {
        printf(", %d excess values discarded", excess);
    }
    printf("\n");
    return n;
}

/* print the elements of an array on one line
 * (insertionsort.c, Figure 7.4 PPSAA) */
void print_int_array(int A[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf(" %3d", A[i]);
    }
    printf("\n");
}

/* function prototypes */
int kth_smallest(int[], int, int);

void create_sorted_array(int A[], int n);

void print_smallest(int k);

/* scaffolding to test the required function*/ 
int main(int argc, char *argv[]) {
    int numbers[MAXVALS];
    int valid = read_int_array(numbers, MAXVALS);

    printf("Before: ");
    print_int_array(numbers, valid);

    /* test some values */
    
    create_sorted_array(numbers, valid);
    print_smallest(valid);

    /* prove that we did not modify the array */
    printf("After: ");
    print_int_array(numbers, valid);

    return 0;
}

// TODO: implement kth_smallest below!

void create_sorted_array(int A[], int n){
	int i;
	int j;
	for(i =0; i<n-1; i++){
		sortedArr[i] = A[i];
	}
	for(i = 0; i<n-2; i++){
		for(j=i+1; j<n-1; j++){
			if(sortedArr[i] > sortedArr[j]){
				int_swap(sortedArr[i], sortedArr[j]);
			}
		}
	}
}

//int kth_smallest(int A[], int n, int k) {
//    int i;
//    int j;
//
//
//	
//    return result;
//}

void print_smallest(int k){
	int i;
	for(i=0; i<k; i++){
		 printf("The %d'th smallest is %d\n", k, sortedArr[i]);
	}
}

