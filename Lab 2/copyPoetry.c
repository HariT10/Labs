#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//By: Harishan Thilakanathan
//
//LAB 2(CIS 2500)

//no word can be greater than 20 characters in length
#define NUM_WORD_LENGTH 20
//no line can be greater than 100 characters in lenght 
#define NUM_LINE_LENGTH 100

//FUNCTION PROTOTYPES 
//void readPoemContent(int words[NUM_WORD_LENGTH], char lines[NUM_LINE_LENGTH]);


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


    //set to NULL because it itnitially doesn't point anywhere 
    char **lines = NULL;
    
    //used in realloc
    int newLine = 0;

    //a pointer named ptr, ptr is pointing to the addres of the dynamically aloocated space created by malloc() 
    char *ptr;
    //a double pointer named ptr2
    char **ptr2;

    int lineCounter = 0;
    int allWords = 0;

    //int wordCounter = 0;


    int wordCounter = 0;
  

    //while to read each line from the poem1.txt or poem2.txt, and store in 'char line[NUM_LINE_LENGTH]' array 
    //no line can have more than NUM_LINE_LENGTH(100 charcters)
    while(fgets(eachLine, NUM_LINE_LENGTH, file) != NULL){

        //put this counter inside the loop, so it resets each time
        wordCounter = 0;

        //to count the amount of lines
        lineCounter = lineCounter + 1;

        char *token = strtok(eachLine, " \t\n");

        
        //after reading the first line, malloc() is used to dynamically allocate memory for that line
        //strlen(line) gets the length and +1 is added for \O
        //ptr is assigned the value of the dynamically allocated memeory created by malloc() to hold the line
        ptr = malloc(strlen(eachLine) + 1); 


        //error handling, as said in the slides, its good to test if a pointer is NULL after a malloc()
        if (ptr == NULL) {
            printf("malloc() has failed to allocate memory\n");
            return 1;
        }

        //copy the line stored in eachLine to where ptr is pointing at, which was set by malloc()
        strcpy(ptr, eachLine);


        //realloc() rizes a previosuly allocated block of memory
        //it is resized because as line 2 comes in, more dynamically allocated memory is needed, so using realloc() it will be resized accordingly 
        ptr2 = realloc(lines, (newLine + 1) * sizeof(char *));


        //error handling, as said in the slides, its good to test if a pointer is NULL after a realloc()
        if (ptr2 == NULL) {
            printf("realloc() has failed to reallocate memory\n");
            return 1;
        }

        while(token != NULL){
            wordCounter = wordCounter + 1;
            token = strtok(NULL, " \t\n");
        }

        /*

        lines = ptr2;
        lines[newLine++] = ptr;

        */

        printf("%d ", wordCounter);
        allWords = allWords + wordCounter;

    }

   

    printf("\n%d Words on ", allWords);
    printf("%d Lines\n", lineCounter);

    

    



    

 

    /*


    for (int i = 0; i < newLine; i++) {

        printf("%s", lines[i]);
        free(lines[i]); // Free memory allocated for each line
    }


    */

   
    fclose(file);

    return 0;


}



