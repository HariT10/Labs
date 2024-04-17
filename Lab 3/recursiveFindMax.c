#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//By: Harishan Thilakanathan(1274198)
//Date: Wed, March 6, 2024
// recursive find max

#define SIZE 10

int recursiveFindMax (int *arr, int size){


    //int maxNumber;

    //base case 
    //if size of array equals 1, then that is the maxNumber
    if(size == 1){;
        return arr[0];
    }
    //generic or recursive case
    else{
        //return 1 + recursiveFindMax();
        int rF = recursiveFindMax(arr + 1, size - 1);

        if(arr[0] > rF){
            return arr[0];
        }else{
            return rF;
        }

    }

return 0;

}

