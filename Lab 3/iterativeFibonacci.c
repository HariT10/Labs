#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//By: Harishan Thilakanathan(1274198)
//Date: Wed, March 6, 2024
// iterative fibonacci


#define SIZE 10

int iterativeFibonacci (int n){

    //from one of the lecture slides 
    int i;
    int oneBack;
    int twoBack;
    int current;

    if(n <= 0){
        return (0);
    }
    else if(n == 1){
        return(1);
    }
    else{
        twoBack = 0;
        oneBack = 1;

        for(i = 2; i <= n; i++){
            current = twoBack + oneBack;
            twoBack = oneBack;
            oneBack = current;
        }
        return(current);
    }
}
