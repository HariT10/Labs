#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//By: Harishan Thilakanathan(1274198)
//Date: Wed, March 6, 2024
// iterative find max

#define SIZE 10

int iterativeFindMax (int *arr, int size){

    int maxNumber = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] > maxNumber){
            maxNumber = arr[i];
        }
    }

    return maxNumber;

}
