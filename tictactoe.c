#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Author: Lev Bernstein
//Purpose: Lose to a perfect tic-tac-toe bot.
//C was probably not the best language for this; Python would've worked much better.
//I wanted to do something in C, though. No real reason.

//Empty spaces in the board are represented with -1.
int board[3][3] = {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}};
int placed = 0;

void printBoard(int board[][3]) {
  int i = 0;
  int j;
  printf("The board looks like this:\n\n");
  for (i; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == -1) {
	printf("   ");
      }
      if (board[i][j] == 0) {
	printf(" O ");
      }
      if (board[i][j] == 1) {
	printf(" X ");
      }
      if (j != 2) {
	printf("|");
      }
    }
    if (i != 2) {
      printf("\n-----------\n");
    }
  }
  printf("\n\n");
}

int movesRemaining(int board[][3]) {
  int i = 0;
  int j;
  for (i; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == -1) {
	return 1;
      }
    }
  }
  return 0;
}

int checkWin(int board[][3]) {
  //Check diagonals:
  if (board[1][1] != -1) {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
      return board[0][0];
    }
    if (board[2][0] == board[1][1] && board[1][1] == board [0][2]) {
      return board[2][0];
    }
  }
  int i = 0;
  int j;
  //Check horizontals/verticals:
  for (i; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] != -1) {
	if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
	  return board[i][0];
	}
	if (i == 0) { //We only need to check the columns once
	  if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
	    return board[0][j];
	  }
	}
      }
    }
  }
  return -1;
}

int move(int board[][3]) {
  /*
  if (placed == 0) {
    board[0][0] = 0;
    return 100;
    }
  if (placed == 1) {
  }
  placed +=1;
  */
  
  return 0;
}

int main() {
  int turn = -1;
  char answer[10];
  char yes[] = "yes";
  char no[] = "no";
  char top[] = "top";
  char middle[] = "middle";
  char bottom[] = "bottom";
  char left[] = "left";
  char right[] = "right";
  int playing = 1;
  int valid = 0;
  int validRow = 0;
  int validColumn = 0;
  int pRow = -1;
  int pColumn = -1;
  char row[10];
  char column[10];
  char temp[255];
  /*
  while (turn == -1) {
    printf("Would you like to go first? Please type 'yes' or 'no'.\n");
    fgets(temp, 256, stdin);
    sscanf(temp, "%s\n", answer);
    answer[0] = tolower(answer[0]); //In case someone types in 'Yes' or 'No', this shifts the first letter down to lowercase. Anyone typing in all caps should simply stop doing so.
    if (strcmp(answer, yes) == 0) {
      turn = 1;
    }
    else if (strcmp(answer, no) == 0) {
      turn = 0;
    }
    else {
      printf("Invalid input! ");
    }
    fflush(stdin);
    }*/
  turn = 1; //Simplifying things for now by always letting the player go first
  printf("I am the great and powerful Tic-Tac-Toe bot! No one can beat me! At best, you can tie.\n");
  while (playing) {
    //printBoard(board);
    //playing = 0;
    if (movesRemaining(board)) {
      if (turn == 1) {
	printBoard(board);
	valid = 0;
	while (!valid) {
	  pRow = -1;
	  pColumn = -1;
	  printf("It is your move. Please type in the cell where you'd like to place your X. You can write something like 'middle row right column' or 'left column bottom row'.\n");
	  fflush(stdin);
	  fgets(temp, 256, stdin);
	  if (sscanf(temp, "%s row %s column", row, column) != 2) {
	    sscanf(temp, "%s column %s row", column, row);
	  }
	  fflush(stdin);
	  valid = 1;
	  if (strcmp(row, top) == 0) {
	    pRow = 0;
	  }
	  else if (strcmp(row, middle) == 0) {
	    pRow = 1;
	  }
	  else if (strcmp(row, bottom) == 0) {
	    pRow = 2;
	  }
	  if (pRow != -1) {
	    if (strcmp(column, left) == 0) {
	      pColumn = 0;
	    }
	    else if (strcmp(column, middle) == 0) {
	      pColumn = 1;
	    }
	    else if (strcmp(column, right) == 0) {
	      pColumn = 2;
	    }
	  }
	  if (pRow == -1 || pColumn == -1) {
	    valid = 0;
	  }
	  else {
	    if (board[pRow][pColumn] != -1) {
	      valid = 0;
	      printf("That cell is already occupied! ");
	    }
	    else {
	      board[pRow][pColumn] = 1;
	      printf("Hmmm. Not the move I would have gone with, but that's fine. ");
	      printBoard(board);
	      placed +=1;
	      turn = 0; //Switch to the bot's turn now
	    }
	  }
	  if (!valid) {
	    printf("Invalid move! ");
	  }
	}
      }
      if (checkWin(board) == 1) {
	turn = 2;
	playing = 0;
	printf("You win!\n");
	exit(0);
      }
      if (turn == 0) {
	printf("Bot's turn \n");
	move(board);
	turn = 1;
      }
      if (checkWin(board) == 0) {
	turn = 2;
	playing = 0;
	printf("You lose!\n");
	exit(0);
      }
    }
    else {
      printf("The board is full! It's a draw!\n");
      turn = 2;
      playing = 0;
      exit(0);
    }
  }
  //printBoard(board);
  return 0;
}
