/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Ng Chun Faat
 * Student ID    : 1155194596
 * Class/Section : D
 * Date          : 3 April 2023
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */



/* Initialize the specified game board.
   Please design your own representation for the game board.  For example:
      - Does gameBoard[0][0] represent the top left corner or the bottom left corner of the game board?
      - Which numbers represent empty cells and crosses? */
void initGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part
    int i, j, count = 1;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            gameBoard[i][j] = count;
            count++;
        }
    }
}



/* Display the specified game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part
    for (int i = 2; i >= 0; i--){
        for (int j = 0; j < 3; j++){

            if (gameBoard[i][j] == 0){
                printf("|x|");
            }else {
                printf("|%d|", gameBoard[i][j]);
            }

        }
        printf("\n");
    }
}



/* Display the two game boards on the screen.
   Implemented for you already and no change is needed */
void printTwoGameBoards(int gameBoard1[3][3], int gameBoard2[3][3]) {
    printf("\n");
    printf("# Game Board 1 #\n");
    printGameBoard(gameBoard1);
    printf("# Game Board 2 #\n");
    printGameBoard(gameBoard2);
}



/* Return 1 if the specified game board is dead (i.e., having three-in-a-row of crosses), otherwise return 0. */
int isGameBoardDead(int gameBoard[3][3]){

    // TODO: Complete this part
    for (int i = 0; i < 3; i++){
        // Checks rows
        if (gameBoard[i][0] == gameBoard[i][1] == gameBoard[i][2]){
            return 1;
        }
        
        // Checks columns
        if (gameBoard[0][i] == gameBoard[1][i] == gameBoard[2][i]){
            return 1;
        }
    }

    // Checks diagonals
    if (gameBoard[0][0] == gameBoard[1][1] == gameBoard[2][2]){
        return 1;
    }
    if (gameBoard[0][2] == gameBoard[1][1] == gameBoard[2][0]){
        return 1;
    }

    return 0;
}



/* Update the specific game board according to the user input.
   The user input may not be valid, but you can assume that it must be an integer. */
void updateGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part

}



/* Choose a game board and place a cross according to the user inputs.
   The user input may not be valid, but you can assume that it must be an integer. */
void placeCrossByHumanPlayer(int gameBoard1[3][3], int gameBoard2[3][3]) {

    // TODO: Complete this part

}



/* Return the number of crosses on the specified game board. */
int countNumOfCrosses(int gameBoard[3][3]) {

    // TODO: Complete this part

}



/* Determine the next move of the computer player and update the corresponding game board accordingly.
   You are required to exactly follow the strategy mentioned in the project specification.
   IMPORTANT: Using other strategies will result in mark deduction. */
void placeCrossByComputerPlayer(int gameBoard1[3][3], int gameBoard2[3][3]) {

    // TODO: Complete this part

}



/* The main function */
int main()
{
    /* Local variables */
    int gameBoard1[3][3];   // Represent Game Board 1
    int gameBoard2[3][3];   // Represent Game Board 2
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameEnd;            // 0: The game continues   1: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */
    initGameBoard(gameBoard1);
    initGameBoard(gameBoard2);
    currentPlayer = 1;
    gameEnd = 0;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid here

    /* Uncomment the following statements to test whether the printTwoGameBoards() and the placeCrossByHumanPlayer() functions are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
    // printTwoGameBoards(gameBoard1, gameBoard2);
    // printf("# Player 1's turn #\n");
    // placeCrossByHumanPlayer(gameBoard1, gameBoard2);
    // printTwoGameBoards(gameBoard1, gameBoard2);
    // printf("# Player 2's turn #\n");
    // placeCrossByHumanPlayer(gameBoard1, gameBoard2);
    // printTwoGameBoards(gameBoard1, gameBoard2);

    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer
       For both cases, Player 1 moves first
       Hint: use a while loop */

    // TODO: Complete this part


    return 0;
}
