#include <stdio.h>
#include <string.h>
#include "lab1.h"

//By: Harishan Thilakanathan
//main fucntion
//Wed, Jan 17, 2024

//constant
#define NUM_EMP 3


int main(int argc, char* argv[]){

    // Specify the filename for the output
    const char *fileName = "names.txt";

    int totalRecords;

    //makes it so that the text file is accepted from the command line
    if(argc != 2){
        printf("Incorrect amount of arguments");
        return 0;
    }

    Employees arrEmployees[NUM_EMP];

    //function 1(part A)

    // Call the function to save employee information to the text file
    saveEmployees(arrEmployees, NUM_EMP, fileName);

    printf("\nSaved to %s.\n", fileName);

    printf("\nBelow is the information that is saved in the array called 'arrEmployees'");
    printf("\nThis information was recieved from the text file");
    printf("\n");


    //function 2(Part A)

    //calling function loadEmployees
    totalRecords = loadEmployees(arrEmployees, fileName);

    //print the array saved information, just to show that the information in the text file has been saved to the array
    for (int i = 0; i < totalRecords; ++i) {
        printf("\n%s\n%s\n%d", arrEmployees[i].fname, arrEmployees[i].lname, arrEmployees[i].id);
    }

    //print the total records, which was attained from the counter in loadEmployees function
    printf("\nTotal Records: %d", totalRecords);
    printf("\n");


    //function 3 - print a employee
    printAnEmployee(arrEmployees[1]);
    printf("\n");


    //fucntion 4

    // Call the function to search for an employee by name
    searchFirstName("Harishan", arrEmployees);


    return 0;


}