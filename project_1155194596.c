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

    // Assign 1-9 to gameBoard with [0][0] being the bottom left cell
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            gameBoard[i][j] = i * 3 + j + 1;
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

            if (gameBoard[i][j] == -1){
                printf("|x");
            }else {
                printf("|%d", gameBoard[i][j]);
            }

        }
        printf("|\n");

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
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]){
            return 1;
        }
        
        // Checks columns
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]){
            return 1;
        }
    }

    // Checks diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]){
        return 1;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]){
        return 1;
    }

    return 0;
}



/* Update the specific game board according to the user input.
   The user input may not be valid, but you can assume that it must be an integer. */
void updateGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part
    int choice;

    printf("Choose the cell:\n");
    
    while (1){
       scanf("%d", &choice);

        if (choice < 1 || choice > 9){
            printf("Input out of range. Please input again:\n");
            continue;
        }

        if (gameBoard[(choice-1)/3][(choice-1)%3] == -1){
            printf("The chosen cell is occupied. Please input again:\n");
            continue;
        }else {
            gameBoard[(choice-1)/3][(choice-1)%3] = -1; // Place cross on chosen cell
            break;
        }

    }

}



/* Choose a game board and place a cross according to the user inputs.
   The user input may not be valid, but you can assume that it must be an integer. */
void placeCrossByHumanPlayer(int gameBoard1[3][3], int gameBoard2[3][3]) {

    // TODO: Complete this part
    int choice;

    printf("Choose the game board:\n");

    while (1){
        scanf("%d", &choice);

        if (choice < 1 || choice > 2){
            printf("Input out of range. Please input again:\n");
        }

        if (choice == 1){
            if (isGameBoardDead(gameBoard1)){
                printf("The chosen game board is dead. Please input again:\n");
                continue;
            }else {
                updateGameBoard(gameBoard1);
                break;
            }
        }

        if (choice == 2){
            if (isGameBoardDead(gameBoard2)){
                printf("The chosen game board is dead. Please input again:\n");
                continue;
            }else {
                updateGameBoard(gameBoard2);
                break;
            }
        }

    }

}



/* Return the number of crosses on the specified game board. */
int countNumOfCrosses(int gameBoard[3][3]) {

    // TODO: Complete this part
    int count = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){

            if (gameBoard[i][j] == -1){
                count++;
            }

        }
    }

    return count;
}



/* Determine the next move of the computer player and update the corresponding game board accordingly.
   You are required to exactly follow the strategy mentioned in the project specification.
   IMPORTANT: Using other strategies will result in mark deduction. */
void placeCrossByComputerPlayer(int gameBoard1[3][3], int gameBoard2[3][3]) {

    // TODO: Complete this part
    int checkPoint = 0; // To store the smallest/largest unoccupied cell

    printf("Choose the game board:\n");

    // Case B: Game board 2 is dead, game board 1 is chosen
    if (isGameBoardDead(gameBoard2)){
        printf("1\n");
        printf("Choose the cell:\n");

        // Place the cross on the unoccupied cell with the smallest number
        for (int i = 0; i < 9; i++){
            if (gameBoard1[(i)/3][(i)%3] != -1){
                
                // Store the smallest unoccupied cell
                if (!checkPoint){
                    checkPoint = i + 1;
                }

                gameBoard1[(i)/3][(i)%3] = -1;

                if (isGameBoardDead(gameBoard1)){
                    gameBoard1[(i)/3][(i)%3] = i + 1; // Revert the cell
                    continue;
                }else {
                    checkPoint = 0; // Reset the varible as we found the good cell
                    printf("%d\n", i + 1);
                    return;
                }
            }
        }

        // Place the cross at checkpoint if no good cell found
        if (checkPoint){
            gameBoard1[(checkPoint-1)/3][(checkPoint-1)%3] = -1;
            printf("%d\n", checkPoint);
        }

    // Case B: Game board 1 is dead, game board 2 is chosen
    }else if(isGameBoardDead(gameBoard1)){
        printf("2\n");
        printf("Choose the cell:\n");

        // Place the cross on the unoccupied cell with the largest number
        for (int i = 8; i >= 0; i--){
            if (gameBoard2[(i)/3][(i)%3] != -1){

                // Store the largest unoccupied cell
                if (!checkPoint){
                    checkPoint = i + 1;
                }

                gameBoard2[(i)/3][(i)%3] = -1;

                if (isGameBoardDead(gameBoard2)){
                    gameBoard2[(i)/3][(i)%3] = i + 1; // Revert the cell
                    continue;
                }else {
                    checkPoint = 0; // Reset the varible as we found the good cell
                    printf("%d\n", i + 1);
                    return;
                }
            }
        }

        // Place the cross at checkpoint if no good cell found
        if (checkPoint){
            gameBoard2[(checkPoint-1)/3][(checkPoint-1)%3] = -1;
            printf("%d\n", checkPoint);
        }

    // Case A: Both game boards are not dead
    }else {
        if (countNumOfCrosses(gameBoard1) < countNumOfCrosses(gameBoard2)){
            printf("1\n");
            printf("Choose the cell:\n");

            // Place the cross on the unoccupied cell with the smallest number
            for (int i = 0; i < 9; i++){
                if (gameBoard1[(i)/3][(i)%3] != -1){
                    gameBoard1[(i)/3][(i)%3] = -1;
                    printf("%d\n", i + 1);
                    return;
                }
            }

        }else {
            printf("2\n");
            printf("Choose the cell:\n");

            // Place the cross on the unoccupied cell with the largest number
            for (int i = 8; i >= 0; i--){
                if (gameBoard2[(i)/3][(i)%3] != -1){
                    gameBoard2[(i)/3][(i)%3] = -1;
                    printf("%d\n", i + 1);
                    return;
                }
            }

        }
    }

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
    if (numOfHumanPlayers == 2){
        while (!gameEnd){
            printTwoGameBoards(gameBoard1, gameBoard2);
            
            printf("# Player %d's turn #\n", currentPlayer);

            placeCrossByHumanPlayer(gameBoard1, gameBoard2);
            currentPlayer = (currentPlayer % 2) + 1;

            // Check if the game has ended
            if (isGameBoardDead(gameBoard1) && isGameBoardDead(gameBoard2)){
                gameEnd = 1;
                printTwoGameBoards(gameBoard1, gameBoard2);
                printf("Congratulations! Player %d wins!", currentPlayer);
            }

        }
    }else if (numOfHumanPlayers == 1){
        while (!gameEnd){
            // Player 1's turn
            printTwoGameBoards(gameBoard1, gameBoard2);
            
            printf("# Player 1's turn #\n");

            placeCrossByHumanPlayer(gameBoard1, gameBoard2);

            // Check if the game has ended after P1's move
            if (isGameBoardDead(gameBoard1) && isGameBoardDead(gameBoard2)){
                gameEnd = 1;
                printTwoGameBoards(gameBoard1, gameBoard2);
                printf("Computer wins!");
                break; // Terminate the program immediately
            }

            // Computer's turn
            printTwoGameBoards(gameBoard1, gameBoard2);
            
            printf("# Computer's turn #\n");

            placeCrossByComputerPlayer(gameBoard1, gameBoard2);

            // Check if the game has ended after Computer's move
            if (isGameBoardDead(gameBoard1) && isGameBoardDead(gameBoard2)){
                gameEnd = 1;
                printTwoGameBoards(gameBoard1, gameBoard2);
                printf("Congratulations! Player 1 wins!");
            }

        }
    }


    return 0;
}
