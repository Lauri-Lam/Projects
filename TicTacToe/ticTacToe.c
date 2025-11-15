#include <stdio.h>
#include <stdbool.h>

void initBoard(char board[3][3]);
void printBoard(char board[3][3]);
void playerMove(char board[3][3], char symbol);
bool hasWon(char board[3][3], char symbol);
bool isBoardFull(char board[3][3]);

int main(){
    char board[3][3];
    char currentPlayer = 'X';

    initBoard(board);

    while(true) {
        printBoard(board);
        playerMove(board, currentPlayer);

        if (hasWon(board, currentPlayer)) {
            printBoard(board);
            printf("Player %c has won!\n", currentPlayer);
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void initBoard(char board[3][3]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            board[r][c] = ' ';
        }
    }
}

void printBoard(char board[3][3]) {
    printf("\n");

    for (int r = 0; r < 3; r++) {
        printf(" %c | %c | %c \n",
        board[r][0], board[r][1], board[r][2]);

        if (r < 2)
            printf("---+---+---\n");
    }
    printf("\n");
}

void playerMove(char board[3][3], char symbol) {
    int row, col;

    while(true) {
        printf("Player %c, enter row (1-3): ");
        scanf("%d", &row);

        printf("Player %c, enter column (1-3): ");
        scanf("%d", &col);

        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("That position is already taken!\n");
            continue;
        }

        board[row][col] = symbol;
        break;
    }
}

bool hasWon(char board[3][3], char symbol) {
    for (int r = 0; r < 2; r++) {
        if (board[r][0] == symbol &&
            board[r][1] == symbol &&
            board[r][2] == symbol)
                return true;
    }

    for (int c = 0; c < 2; c++) {
        if (board[0][c] == symbol &&
            board[1][c] == symbol &&
            board[2][c] == symbol)
                return true;
    }

    if (board[0][0] == symbol &&
        board[1][1] == symbol &&
        board[2][2] == symbol)
            return true;

    if (board[0][2] == symbol &&
        board[1][1] == symbol &&
        board[2][0] == symbol)
            return true;

    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            if (board[r][c] != ' ')
                return false;
        }
    }
    return true;
}