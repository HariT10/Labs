#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// By: Harishan Thilakanathan
// Wed, Feb 7, 2023
// LAB 2(CIS 2500) - read from lines from poem text file, but dynamically store the arrays 

//no word can be greater than 20 characters in length
#define NUM_WORD_LENGTH 20
//no line can be greater than 100 characters in lenght 
#define NUM_LINE_LENGTH 100


int main(int argc, char *argv[]){

    //take in the c file and the text file
    if(argc != 2){
        printf("Usage: %s <filename>", argv[0]);
        return 1;
    }

    FILE* file = fopen("poem1.txt", "r");

    //check for NULL(doing so is a good practice)
    if(file == NULL){
        printf("ERROR, CANNOT OPEN FILE");
        //if the given file does not exist, the function returns -1
        exit(-1);
    }


    //variable for the words, less then 20 charcaters 
    //int words[NUM_WORD_LENGTH];

    //variable for lines, no line can have more then 100 charcters 
    char eachLine[NUM_LINE_LENGTH];


    //used in realloc
    int newLine = 0;


    //a counter to count each line, so counter updates each iteration of the while loop
    int lineCounter = 0;

    //a counter for all the words
    int allWords = 0;


    //after reading the first line, malloc() is used to dynamically allocate memory for that line
    //strlen(line) gets the length and +1 is added for \O
    //malloc(strlen(eachLine) + 1) allocates memory to store charcters 
    //malloc(strlen(eachLine) + 1); 

    //REMEMBER: int takes up more space then char, and double takes the most


    //dynamically stored array, no allocated value at the moment, thats why its NULL
    int * array = NULL;

    //malloc(sizeof(int) * 1) allocates to store one integer, this will get reollocated in the while loop as it reads more lines
    array = malloc(sizeof(int) * 1); 


    //error handling, as said in the slides, its good to test if a pointer is NULL after a malloc()
    if (array == NULL) {
        printf("malloc() has failed to allocate memory\n");
        return 1;
    }
    

    //while to read each line from the poem1.txt or poem2.txt, and store in 'char line[NUM_LINE_LENGTH]' array 
    //no line can have more than NUM_LINE_LENGTH(100 charcters)
    while(fgets(eachLine, NUM_LINE_LENGTH, file) != NULL){

        //put this counter inside the loop, so it resets each time
        int wordCounter = 0;

        //to count the amount of lines
        lineCounter = lineCounter + 1;


        //realloc() rizes a previosuly allocated block of memory, so 'array' gets resized
        //it is resized because as line 2 comes in, more dynamically allocated memory is needed, so using realloc() it will be resized accordingly 
        array = realloc(array, sizeof(int) * (newLine + 1));

        //error handling, as said in the slides, its good to test if a pointer is NULL after a realloc()
        if (array == NULL) {
            printf("realloc() has failed to reallocate memory\n");
            return 1;
        }


        //so if a space " " is encoutnered then 1 is added to the wordCounter
        //this is because if there is a space that mean a word just finished
        char *token = strtok(eachLine, " ");

        while(token != NULL){
            wordCounter = wordCounter + 1;
            token = strtok(NULL, " ");
        }

        //save the wordCounter value for the line, inside the array
        array[newLine] = wordCounter;

        //newLine count goes up by one, to store the next set of words in the newLine
        newLine = newLine + 1;

        //adding all the words, to get the total amount of words
        allWords = allWords + wordCounter;

    }

    //print all the words and amount of lines
    printf("\n%d Words on %d Lines \n", allWords, lineCounter);


    //print the values in array, for every line hence 'i < newLine"]'
    for(int i = 0; i < newLine; i++){
        printf("%d ", array[i]);

    }
        
   
    fclose(file);

    return 0;


}



