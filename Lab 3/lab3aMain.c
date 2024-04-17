#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab3.h"

//By: Harishan Thilakanathan(1274198)
//Date: Wed, March 6, 2024
// iterative fibonacci, recursive fibonacci, iterative find max, recursive find max

#define SIZE 10

//PROTOTYPES
int iterativeFindMax (int *arr, int size);
int recursiveFindMax (int *arr, int size);

int iterativeFibonacci (int n);
int recursiveFibonacci (int n);

//main
int main(){

    //
    double timeElapsed = 0.0;

    clock_t begin, end;

    begin = clock();

    int * arr = NULL;

    int size;

    int n;

    //enter input value
    printf("\nPlease enter input value: ");
    scanf("%d", &n); 

    int iF = iterativeFibonacci(n);

    printf("\nFibanoci using iterative is: %d", iF);

    end = clock();

    timeElapsed += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime elpased is %lf second\n", timeElapsed);

    printf("\n-------------------------------------------------");

    begin = clock();


    int rF = recursiveFibonacci(n);

    printf("\nFibanoci using recursive is: %d", rF);

    end = clock();

    timeElapsed += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime elpased is %lf second\n", timeElapsed);

    printf("\n-------------------------------------------------");

    begin = clock();
 
    //enter size of array
    printf("\nPlease enter array size: ");
    scanf("%d", &size); 

    //dynamci allocation
    arr = malloc(sizeof(int) * size);

    //enter elements for the size
    for(int i = 0; i < size; i++){

        printf("Please enter a number: ");
        scanf("%d", &arr[i]);

    }

    //call the iterative find max fucntion
    int maxI = iterativeFindMax(arr, size);

    printf("\nThe max number useing iterative method is: %d", maxI);

    end = clock();

    timeElapsed += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime elpased is %lf second\n", timeElapsed);

    printf("\n-------------------------------------------------");

    begin = clock();

    //call the recursive find max fucntion
    int maxR = recursiveFindMax(arr, size);

    printf("\nThe max number using recursion method is: %d", maxR);

    end = clock();

    timeElapsed += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime elpased is %lf second\n", timeElapsed);


    printf("\n-------------------------------------------------");


}