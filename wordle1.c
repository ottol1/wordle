/*************
*wordle proj 1
*
*************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void green(){
  printf(" \e[1;32m");
}

void yellow() {
  printf("\033[1;33m");
}




   int main(){
     
     char l1, l2, l3, l4, l5;
     int x,tries=0;

// instructions to play
     printf("How to play\n");
     printf("Each of your guesse must be a 5 letter word\n");
     printf("The color of the tiles will change to show you how close your guess was\n");
     printf("green- letter is in the correct spot, yellow- in the word but wrong spot, white-is not in the word\n");

     FILE* file = fopen("wordle.txt","r");
     if (file == NULL){
        printf("The file cannot be opened\n");
        return 1;
     }
     srand(time(NULL));
     char word[6];
     for (x=0;x<rand()%95;x++){
     fscanf(file,"%s",word);
     }
     printf("%s\n", word);
     
     
     
     
     





    // while(tries <= 6);
 
     
   //  for(tries=o; tries<=6; tries++){
     //  printf("attempt 1: %c %c %c %c %c", l1, l2, l3, l4, l5         










return 0;
}
