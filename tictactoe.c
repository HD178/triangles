#include <stdio.h>
#include <stdlib.h>

/*
 * - Initialise board
 * function : initialise() 
 * params : -
*/
char** initialise() {
  //allocate memory to pointers to rows of board
  char** board = malloc(3 * sizeof(char));
  //allocate memory for each row 
  for (int i = 0; i < 3; i++) {
    board[i] = malloc(3 * sizeof(char));
  }

  //initialise elements in board 
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = '.';
    }
  }

  return board;
}

/* 
 * - Prints current board 
 * function : print()
 * params: 
 *    board : char** 
*/
void print(char** board) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c", board[i][j]);
      if (j < 2) printf(" | ");
    }
    if (i<2) printf("\n----------\n");
    else printf("\n");
  }
}

/* 
 * - Checks for winner
 * function : win()
 * params: 
 *    board : char** 
 * return: int (0 lost, 1 win)
*/
int win(char** board) {
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] != '.' && board[i][1] != '.' && board[i][2] != '.') && //check not empty 
        ((board[i][0] == board[i][1] && board[i][1] == board[i][2])  || //check row 
        (board[0][i] == board[1][i] && board[1][i] == board[2][i]) || //check column 
        (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || //check diagonal (left to right)
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) //check diagonal (right to left)
    ) {
      return 1;
    }
  }
  return 0;
}

/* 
 * - Checks if board is full and there are no matches 
 * function : gameOver()
 * params: 
 *    board : char** 
 * return: int (0 not over, 1 over)
*/
int gameOver(char** board) {
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != '.') {
        count++;
      }
    }
  }
  if (count == 9) { 
    return 1;
  }
  return 0;
}

/* 
 * - Checks if player move is valid and updates board
 * function : valid()
 * params: 
 *    board : char** 
 *    player : char
 *    pos : int 
 * return: int (0 not valid, 1 valid)
*/
int update(char** board, char player, int pos) {
  //row index = pos%3
  //column = pos/3
  if (board[pos/3][pos%3] != '.') { 
    return 0;
  }
  char s = ' ';
  if (player == 1) s = 'X';
  else if (player == 2) s = 'O';
  board[pos/3][pos%3] = s;
  return 1;
}


/* 
 * - Main game loop, initialise game board 
 * function : main()
 * params: -
*/
int main(void) {
  printf("Tic-Tac-Toe \n");
  printf("0 | 1 | 2\n");
  printf("----------\n");
  printf("3 | 4 | 5\n");
  printf("----------\n");
  printf("6 | 7 | 8\n");
  printf("\n");

  char** board = initialise();
  print(board);

  int pos = -1;
  int player = 1;

  while (!gameOver(board) || !win(board)) {
      printf("Player %d: ", player);
      scanf("%d", &pos);
      printf("\n");

      if (pos > 8 || pos < 0) { 
        printf("Invalid input. Enter a number in the grid\n");
      }
      else if (!update(board, player, pos)) {
        printf("Space taken! Choose another number\n");
      }
      
      else { 
        print(board);

        //check game state
        if (win(board)) {
          printf("player %d wins!\n", player);
          return 0;

        }
        else if (gameOver(board)) {
          printf("Tie!\n");
          return 0;
        }

        //switch roles 
        if (player == 1) player = 2;
        else if (player == 2) player = 1;
      }
    }

  return 0;
}


/*
Segmentation Fault 
  - Allocating space for char instead of char* (pointer)
  - Wrong format specifier used 
  - scanf writes to an address (not just variable)
*/