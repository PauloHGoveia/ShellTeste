#include <stdio.h>
#include <stdlib.h>

// A command line bigger than 1024 chars doesn't deserve to be taken seriously
#define BUFFSIZE 1024

void main(){
 char *buffer = malloc(sizeof(char)*BUFFSIZE);
 int position = 0;
 int c;

 if(!buffer){
  fprintf(stderr, "allocation error!\n");
  exit(EXIT_FAILURE);
 }

 // while forever
 while(1){
  // get a char
  c = getchar();

  // if EOF (End Of File) or "new line", replace with NULL (\0)
  // printf the content and exit
  if(c == EOF || c == '\n'){
   buffer[position] = '\0';
   printf("%s\n", buffer);
   exit(EXIT_SUCCESS);
  } else {
   buffer[position] = c;
  }
  position++;
 }
}
