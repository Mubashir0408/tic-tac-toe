
#include<iostream>
using namespace std;


char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int currentPlayer = 1;

void drawBoard() {                      // MBASHIR EJAZ                                                   
   
   
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
 }                                                                                       

bool placeMarker(int slot, char marker) {  // MOIZ 

    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] == ' ') {      
        board[row][col] = marker;
        return true;
    }
    return false;
}

bool isBoardFull() { // LIBA 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
		 {
                if (board[i][j] == ' ') 
		           	{
                return false; 
                }
        }
    }
    return true; 
}
int checkWinner() {   // ESMAL
   
    for (int i = 0; i < 3; i++) 
	{
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
		{
            return currentPlayer;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
		{
            return currentPlayer;
        }
          }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	 {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') 
	{
        return currentPlayer;
       }
    return 0;
}

void switchPlayer() {                // moiz
    
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}
void resetBoard() {                           // mubashir EJAZ F2024266305
     for (int i = 0; i < 3; i++)
	  {
        for (int j = 0; j < 3; j++) 
		{
            board[i][j] = ' ';
        }
    }
    currentPlayer = 1; }

void game() {                       // MUBARRAH 
    int slot;
    char marker;
    int winner = 0;
    
    while (true) {
        drawBoard();
        marker = (currentPlayer == 1) ? 'X' : 'O';
        cout << "Player " << currentPlayer << ", enter your slot (1 to 9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot, try again" << endl;
            continue;
        }

        if (!placeMarker(slot, marker)) {
            cout << "Slot already taken, try again" << endl;
            continue;
        }
        

        winner = checkWinner();
        if (winner) {
            drawBoard();
            cout << "Player " << winner << " win the game, congragulation!" << endl;
            break;
        }

        switchPlayer();
        if (isBoardFull()) { 
            drawBoard();
            cout << "It's a draw!" << endl;
            break;}

      }
}

int main() { // MBASHIR EJAZ
	char playAgain;
    do {
        resetBoard(); 
        game();       
        cout << "Do you want to play again? yes or no: ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing" << endl;
    return 0;
    
}
