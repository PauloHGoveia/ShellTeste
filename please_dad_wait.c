#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(){
 int pid, wpid;
 int status;

 pid = fork();

 //Ok, fork returned an error
 if(pid == -1){
  printf("fork() failed\n");
  exit(EXIT_FAILURE);
 }

 // I am the SON
 if(pid == 0){
  // just doing something
  for(int i = 0; i < 5; i++){
   printf("Dad is watting: %d\n", i);
   sleep(1);
  }
 } else { // I am your FATHER
  // waiting for the BOY!
  wpid = waitpid(pid, &status, WUNTRACED);
  printf("BOY is dead!\n");
 }
}
