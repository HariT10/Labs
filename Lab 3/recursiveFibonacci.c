#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//By: Harishan Thilakanathan(1274198)
//Date: Wed, March 6, 2024
// recursive fibonacci


#define SIZE 10

int recursiveFibonacci (int n){

    //base case
    if( n == 0){
        return(0);
    }
    else if(n == 1){
        return (1);
    }
    //recursive case
    else{
        //calls twice
        return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);

    }

}
