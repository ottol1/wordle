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

// The following function gives feedback for each spot in the array for the guess. Once a spot in the array is given feedback we stop giving feedback for that spot. This prevents double letters from becoming an issue.
void giveFeedback(char word[5], char guess1[5], int feedback[5]){
   int i,j;
   int y[5]= {0,0,0,0,0};
   for(i=0;i<5;i++){
       if(word[i]==guess1[i]){ //This section checks for letters in the right spot. Gives feeback 1.
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
                feedback[j]=2; // Checks for yellow letters and gives feedback 2
                y[i]=1;
                break;
            }
        }
    }
}

// The following function prints the feedback from the giveFeedback function. So if the feedback is 1 it will print the letter in that spot green. If feeedback is 2 it prints green and if feedback is anything else it prints white. 
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

// Initializing our variables
     char guess1[5];
     int feedback[5] = {0,0,0,0,0};
     int x,tries=1,i=0,j = 0;

// Printing the instructions to play to the screen
     printf("How to play\n");
     printf("Each of your guesses must be a 5 letter word and lowercase\n");
     printf("The color of the tiles will change to show you how close your guess was\n");
     printf("green: letter is in the correct spot\nyellow: letter is in the word but in the wrong spot\nwhite: letter is not in the word\n");

// The following code opens our file with a list of 5 letter words and checks if the file opens correctly
     FILE* file = fopen("wordle.txt","r");
     if (file == NULL){
        printf("The file cannot be opened\n");
        return 1;
     }
     
// This section of code randomly scans in a word from our list for the user to guess
     srand(time(NULL));
     char word[6];
     for (x=0;x<rand()%95;x++){
     fscanf(file,"%s",word);
     }
     //printf("%s\n", word); // shows word just for testing, comment out to play game
     
 // In the game the user has 6 guesses. The following while loop keeps track of the tries and keeps looping till the user has guessed the word or run out of tries.
   while (tries < 7){
   
     // The following 5 lines resets the feedback array to all zeroes for each new guess.
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
     
// The following if statement checks to ensure the user guesses 5 letters. Guessing too many or too few gives an error.
     if ((strlen(guess1)>5)||(strlen(guess1)<5)){ 
       printf("Error guess has too many or too few letters try again\n");
       tries=tries-1;
      continue;
     }
     
// The following if statement checks for uppercase letters.
     if ((isupper(guess1[0]))||(isupper(guess1[1]))||(isupper(guess1[2]))||(isupper(guess1[3]))||(isupper(guess1[4]))){ 
       printf("Error guess has uppercase letter\n");
       tries=tries-1;
       continue;
     }
     
// The following if statement checks if the user guessed the right word. If the guess is correct they win and the game ends.
     if (strcmp(word,guess1)==0){
       green(guess1);
       printf("%c%c%c%c%c\n",guess1[0],guess1[1],guess1[2],guess1[3],guess1[4],guess1[5]);
       printf("YOU WON!!\n");
       return 5;
     }
     
// The following two lines run our giveFeedback & printFeedback functions. So if the user guesses a valid word and it isn't correct each individual letter is checked and feedback is  given.
     giveFeedback(word,guess1,feedback);
     printFeedback(feedback,guess1);
   
     printf("\n");
   }
   
// The following if statement checks for the amount of guesses. So once the user has made 6 guesses without guessing the correct word it ends the game
   if (tries = 7){
     white();
     printf("Game Over, out of tries\n");
     printf("The word was %s\n",word);
   }
return 0;
}
