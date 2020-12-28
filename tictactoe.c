#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Author: Lev Bernstein
//Purpose: Lose to a perfect tic-tac-toe bot.

int main() {
  int first = -1;
  char answer[10];
  char yes[] = "yes";
  char no[] = "no";
  int board[3][3] = {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}};
  int playing = 1;
  
  while (first == -1) {
    printf("Would you like to go first? Please type 'yes' or 'no'.\n");
    scanf("%s", answer);
    answer[0] = tolower(answer[0]); //In case someone types in 'Yes' or 'No', this shifts the first letter down to lowercase. Anyone typing in all caps should stop doing so.
    if (strcmp(answer, yes) == 0) {
      first = 1;
    }
    else if (strcmp(answer, no) == 0) {
      first = 0;
    }
    else {
      printf("Invalid input! ");
    }
    fflush(stdin);
  }

  while (playing) {
    
    
  }
  
  return 0;
}
