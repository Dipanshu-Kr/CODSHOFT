#include <iostream>
using namespace std;
int currentPlayer;
char currentMarker;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    // cout << "---|---|---" << endl;
}
bool placemarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }
    else
    {
        return false;
    }
}
int winner()
{
    // rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return currentPlayer;
        }
    }
    // column
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return currentPlayer;
        }
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return currentPlayer;
    }
    return 0;
}
void swapPlayerandMarker()
{
    if (currentMarker == 'X')
    {
        currentMarker = 'O';
    }
    else
    {
        currentMarker = 'X';
    }
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else
    {
        currentPlayer = 1;
    }
}
void game()
{
    char markerP1;
    cout << "Player 1 choose your marker X or O: ";
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;
    drawBoard();
    int playerwon = 0;
    for (int i = 0; i < 9; i++)
    {
        cout << "It's player " << currentMarker << " turn, Enter your slot: ";
        int slot;
        cin >> slot;
        if (slot < 1 || slot > 9)
        {
            cout << " Invalid slot! Try again";
            i--;
            continue;
        }
        if (!placemarker(slot))
        {
            cout << "Slot already occupied! Try again" << endl;
            i--;
            continue;
        }
        drawBoard();
        playerwon = winner();
        if (playerwon == 1)
        {
            cout << "Player 1 Wins" << endl;
            break;
        }
        if (playerwon == 2)
        {
            cout << "Player 2 wins" << endl;
            break;
        }
        swapPlayerandMarker();
        
    }
    if(playerwon == 0){
            cout << "It's tie!" << endl;
    }
}
int main()
{
    char playAgain;
    do{
    game();
    cout << "Do you want to play another game(Y/y): ";
    cin >> playAgain;
    }
    while(playAgain == 'Y' || playAgain == 'y');
    
    return 0;
}