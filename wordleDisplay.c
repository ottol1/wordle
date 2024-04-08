/***********************************
* Wordle Project
* Lauren Otto & Paytn Barnette
* CS 125 Spring 2024
* Resources: Professor Marriott
***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include"wordle.h"
#include<ctype.h>


void giveFeedback(char word[5], char guess1[5], int feedback[5]){
   int i,j;
   int y[5]= {0,0,0,0,0};
   for(i=0;i<5;i++){
       if(word[i]==guess1[i]){ 
           feedback[i]=1;
           y[i] = 1;
       }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i==j){
                continue;
            }
            if((word[i] == guess1[j])&&(y[i]==0)&&(feedback[j]==0)){ 
                feedback[j]=2; 
                y[i]=1;
                break;
            }
        }
    }
}

void printFeedback(int feedback[5],char guess1[5]){
   int i;
    for(i=0;i<5;i++){
        if (feedback[i]==0){
            printf("%c",guess1[i]);
        }
        else if (feedback[i]==1){
            green();
            printf("%c",guess1[i]);
        }
        else {
            yellow();
            printf("%c", guess1[i]);
        }
        white();
    }
}

int main(){


     char guess1[5];
     int feedback[5] = {0,0,0,0,0};
     int x,tries=1,i=0,j = 0;


     printf("How to play\n");
     printf("Each of your guesses must be a 5 letter word and lowercase\n");
     printf("The color of the tiles will change to show you how close your guess was\n");
     printf("green: letter is in the correct spot\nyellow: letter is in the word but in the wrong spot\nwhite: letter is not in the word\n");


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
     printf("%s\n", word); // just for testing, delete to play game
     

   while (tries < 7){
     feedback[0] = 0;  
     feedback[1] = 0;
     feedback[2]= 0;
     feedback[3]=0;
     feedback[4]=0;
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
       if ((isupper(guess1[0]))||(isupper(guess1[1]))||(isupper(guess1[2]))||(isupper(guess1[3]))||(isupper(guess1[4]))){ 
         printf("Error guess has uppercase letter\n");
         tries=tries-1;
         continue;
       }
     
     if (strcmp(word,guess1)==0){
       green(guess1);
       printf("%c%c%c%c%c\n",guess1[0],guess1[1],guess1[2],guess1[3],guess1[4],guess1[5]);
       printf("YOU WON!!\n");
       return 5;
     }

     giveFeedback(word,guess1,feedback);
     printFeedback(feedback,guess1);
   
     printf("\n");
   }

   if (tries = 7){
     white();
     printf("Game Over, out of tries\n");
     printf("The word was %s\n",word);
   }
return 0;
}
