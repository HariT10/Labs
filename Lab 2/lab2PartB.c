#include <stdio.h>
#include <string.h>

int main () 
{
   struct info {
      char name[10];
      int  id;
   };

   typedef struct info record;
   
   record item;
   record newItem[10];

   FILE *fptr;
   int i;
    
   char names[10][40] = {"Fred","John","Mary","Ford","Gert","Hamm","Will","Bill","Paul","Samm"};

   fptr = fopen ( "data", "w+" );
   for ( i=0; i<10; i++ ) {
      strcpy ( item.name, names[i]);
      item.id = i;
      fwrite ( &item, sizeof(item), 1, fptr );
   }
   
   // TO DO

   rewind(fptr);


   fread(newItem, sizeof(item), 10, fptr);

   printf("The name: %s", newItem[0].name);
   printf("\nThe ID: %d", newItem[0].id);

   printf("\nThe name: %s", newItem[2].name);
   printf("\nThe ID: %d", newItem[2].id);



   
   return 0;
}
