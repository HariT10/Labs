#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"

//By: Harishan Thilakanathan
//functions saveEmployees and loadEmployees for lab1A.c
// Wed, Jan 17, 2024

//constant
#define NUM_EMP 3


//Function 1
//3 parameters
//array named "arrEmployees" of size "NUM_EMP", each element is of type Employees
//need to save employee information in a text file
void saveEmployees(Employees arrEmployees[NUM_EMP], int c, const char *fileName){


    //to save employee information in text file
    //we need to open a new text file, that we can write into
    FILE* file = fopen("names.txt", "w");

    //check NULL
    if(file == NULL){
        printf("ERROR, can't open file");
        exit(0);
    }


    //save information(fname, id and dependents) in text file
    //use for loop becuase number of employee is 3, so need to save information of 3 people(3 times)
    //return nothing  
    for(int i = 0; i < 3; i++){

        //fprintf(file,"First Name: %s Last Name: %s ID: %d Dependents: %c", arrEmployees[i].fname, arrEmployees[i].lname, arrEmployees[i].id, arrEmployees[i].dependents);
        
        //ask user to enter first name of the first employee
        printf("\nFirst Name: ");
        scanf("%s", arrEmployees[i].fname);

        //ask user to enter last name of the first employee
        printf("\nLast Name: ");
        scanf("%s", arrEmployees[i].lname);

        //ask user to enter ID of first employee
        //ask user to enter first name of the first employee
        printf("\nID: ");
        scanf("%d", &arrEmployees[i].id);

        //we have to assume that each emplooyee has 3 REGISTERED DEPENDENTS
        for(int j = 0; j < 3; j++){

            printf("\nDependent: ");
            scanf("%s", arrEmployees[i].dependents[j]);

        }

        //then the code will loop and ask for second employee infromation
        //then loop again to ask for third employee information

        //stores the information into the text file
        fprintf(file,"\nFirst Name: %s \nLast Name: %s \nID: %d \nDependent: \n%s \n%s \n%s" , arrEmployees[i].fname, arrEmployees[i].lname, arrEmployees[i].id, arrEmployees[i].dependents[0], arrEmployees[i].dependents[1], arrEmployees[i].dependents[2]);

    }

}


//Function 2
//2 parameters
//read employee records from text file, then load into array
int loadEmployees(Employees arrEmployees[NUM_EMP], const char *fileName){

    //total records variable counter 
    int totalRecords = 0;

    //to read information from the text file
    //we need to open a new text file, that we can be read
    FILE* file = fopen(fileName, "r");

    //check for NULL
    if(file == NULL){
        printf("ERROR, can't open file");
        exit(0);
    }

    //went back to look at assignment 3 from CIS 1300 because we did something similar in that one
    //the for loop will do 0, 1, and 2, then stop
    //values are read from the text file then stored in the array 
    for(int i = 0; i < NUM_EMP; i++){
        fscanf(file, "\n%s \n%s \n%d \n%s \n%s \n%s", arrEmployees[totalRecords].fname, arrEmployees[totalRecords].lname, &arrEmployees[totalRecords].id, arrEmployees[totalRecords].dependents[0], arrEmployees[totalRecords].dependents[totalRecords], arrEmployees[totalRecords].dependents[2]);
        
        //each time an employee record is added the counter increases 
        totalRecords++;

    }

    //close file
    fclose(file);

    //return total records 
    return totalRecords;

}



