#include <stdio.h>
//Function to change letters green
void green(){
  printf("\e[1;32m");
}

//Function to change letters yellow
void yellow() {
  printf("\033[1;33m");
}

//Function to change letters white
void white(){
   printf("\033[0m");
}
