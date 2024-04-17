#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

//By: Harishan Thilakanathan
//functions printAnEmployee and searchFirstName for lab1B.c
// Wed, Jan 17, 2024

//constants
#define NUM_EMP 3

//function 1
void printAnEmployee(Employees emp){

    // Print information for the selected employee
    printf("\n");
    printf("\nFirst Name: %s", emp.fname);
    printf("\n");
    printf("\nLast Name: %s", emp.lname);
    printf("\n");
    printf("\nID: %d", emp.id);
    printf("\n");
    printf("\nDependent: %s\n%s\n%s\n", emp.dependents[0], emp.dependents[1], emp.dependents[2]);

    //the output spacing in the terminal looked bad, so I spaced everything out :)
}

//function 2
int searchFirstName(char firstN[], Employees emp[]){

    //for loop to check if the given name is in the records, aka the array of first names(arrEmployees)
    for(int i = 0; i < NUM_EMP; i++){
        //if the name is indeed in the list of first names
        if(strcmp(emp[i].fname, firstN) == 0){
            //then print the ID of that employee
            printf("\nThe id of the employee is: %d", emp[i].id);
        }
    }

    //when no match is found
    return -1;

}







