/*************
*wordle proj 1
*
*************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include"wordle.h"


int main()
{
     char guess1[7];
     int x,tries=1,i=0,status;

// printing the instructions to play
     printf("How to play\n");
     printf("Each of your guesse must be a 5 letter word all lowercase\n");
     printf("The color of the tiles will change to show you how close your guess was\n");
     printf("green- letter is in the correct spot, yellow- in the word but wrong spot, white-is not in the word\n");

// The following code opens our file with a list of 5 letter words and checks if the file opens correctly
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
     printf("%s\n", word); // just for testing, delete in final code
     
   while (tries < 7){
     white(guess1);
     white(tries);
     printf("guess %d:",tries);
     scanf("%s", guess1);
     tries++;
     if ((strlen(guess1)>5)||(strlen(guess1)<5)){
       printf("Error guess has too many or too few letters try again\n");
       tries=tries-1;
      continue;
     }
     if (strcmp(word,guess1)==0){
       green(guess1);
       printf("%c%c%c%c%c\n",guess1[0],guess1[1],guess1[2],guess1[3],guess1[4],guess1[5]);
       printf("YOU WON!!\n");
       return 5;
     }
     for (i=0; i<5; i++){
       if (word[i] == guess1[i]){
         green(guess1[i]);
         printf("%c",guess1[i]);
       }
       else if((guess1[i]==word[0])||(guess1[i]==word[1])||(guess1[i]==word[2])||(guess1[i]==word[3])||(guess1[i]==word[4])){ 
         yellow(guess1[i]);
         printf("%c",guess1[i]);
       } 
       else{
         white(guess1[i]);
         printf("%c",guess1[i]);
       } 
     } 
     printf("\n");
   }
   if (tries = 7){
     white();
     printf("Game Over, out of tries\n");
   }
return 0;
}