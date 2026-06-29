#include <iostream>
using namespace std;

char board[3][3];

// Initialize the board
void initializeBoard()
{
    char ch = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }
}

// Display the board
void displayBoard()
{
    cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        cout << " ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j != 2)
                cout << " | ";
        }

        cout << endl;

        if (i != 2)
            cout << "-----------" << endl;
    }

    cout << endl;
}

// Check if move is valid
bool isValidMove(int position)
{
    if (position < 1 || position > 9)
        return false;

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    return true;
}

// Place player's symbol
void makeMove(int position, char player)
{
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    board[row][col] = player;
}

// Check winner
bool checkWinner(char player)
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

int main()
{
    char playAgain;

    cout << "=====================================\n";
    cout << "       TIC TAC TOE GAME\n";
    cout << "=====================================\n";

    do
    {
        initializeBoard();

        char currentPlayer = 'X';

        while (true)
        {
            displayBoard();

            int position;

            cout << "Player " << currentPlayer << ", Enter Position (1-9): ";
            cin >> position;

            if (!isValidMove(position))
            {
                cout << "\nInvalid Move! Try Again.\n";
                continue;
            }

            makeMove(position, currentPlayer);

            if (checkWinner(currentPlayer))
            {
                displayBoard();

                cout << "Congratulations!\n";
                cout << "Player " << currentPlayer << " Wins!\n";
                break;
            }

            if (checkDraw())
            {
                displayBoard();

                cout << "Game Draw!\n";
                break;
            }

            if (currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "\nDo You Want To Play Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You For Playing!\n";

    return 0;
}
