#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayBoard(char board[3][3]);
bool placeMove(char board[3][3], int pos, char player);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
int getRandomMove(char board[3][3]);

int main() {
    srand(time(0));
    char board[3][3];
    char player = 'X';
    char again;
    
    do {
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) board[i][j] = ' ';
        bool gameOver = false;
        
        while (!gameOver) {
            displayBoard(board);
            
            if (player == 'X') {
                int pos;
                cout << "X (1-9): ";
                cin >> pos;
                if (pos < 1 || pos > 9 || !placeMove(board, pos, player)) {
                    cout << "Invalid!" << endl;
                    continue;
                }
            } else {
                int move = getRandomMove(board);
                placeMove(board, move, player);
                cout << "O: " << move << endl;
            }
            
            if (checkWin(board, player)) {
                displayBoard(board);
                cout << player << " WINS!" << endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "DRAW!" << endl;
                gameOver = true;
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        }
        
        cout << "Again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    
    return 0;
}

void displayBoard(char board[3][3]) {
    cout << "\nPositions:     Board:" << endl;
    cout << " 1 | 2 | 3     " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---+---+---    ---+---+---" << endl;
    cout << " 4 | 5 | 6     " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---+---+---    ---+---+---" << endl;
    cout << " 7 | 8 | 9     " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl << endl;
}

bool placeMove(char board[3][3], int pos, char player) {
    int r = (pos - 1) / 3, c = (pos - 1) % 3;
    if (board[r][c] == ' ') {
        board[r][c] = player;
        return true;
    }
    return false;
}

bool checkWin(char board[3][3], char p) {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p ||
            board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    return (board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
           (board[0][2] == p && board[1][1] == p && board[2][0] == p);
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (board[i][j] == ' ') return false;
    return true;
}

int getRandomMove(char board[3][3]) {
    int moves[9] = {1,2,3,4,5,6,7,8,9}, cnt = 0;
    for (int i = 1; i <= 9; i++) {
        int r = (i-1)/3, c = (i-1)%3;
        if (board[r][c] == ' ') moves[cnt++] = i;
    }
    return moves[rand() % cnt];
}
