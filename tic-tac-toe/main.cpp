#include <iostream>
#include <windows.h>

using namespace std;

HANDLE h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'O';
int option, moves;
int row, column;

void show_board() {

    cout << endl;
    cout << "                 |     |     \n"
         << "              " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n"
         << "            -----|-----|-----\n"
         << "              " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n"
         << "            -----|-----|-----\n"
         << "              " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n"
         << "                 |     |     \n";
    cout << endl;
}


void again() {

    int winner_option;
    SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << "Do you want to play again or exit? \n"
         << "1. Play Again \n"
         << "2. Exit \n"
         << "Your option: "; cin >> winner_option;

    if (winner_option == 1)
    {
       board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
       board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
       board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
       moves = 0;
    }
    else if (winner_option == 2)
        exit(0);
    system("cls");

}

void draw() {
    SetConsoleTextAttribute(h0ut, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "DRAW!" << endl;

    again();
}

void winner() {

    if (turn == 'X')
        turn = 'O';
    else if (turn == 'O')
        turn = 'X';
    SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
    cout << "Player " << turn << " have won!" << endl;

    again();
}

void judge()
{
    //pionowo
    if ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        || (board[2][0] == board[2][1] && board[2][1] == board[2][2]))
        winner();
    //poziomo
    else if ((board[0][0] == board[1][0] && board[1][0] == board[2][0]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1])
             || (board[0][2] == board[1][2] && board[1][2] == board[2][2]))
        winner();
    //na skos
    else if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        winner();
    else if (moves == 9)
        draw();
}

int main()
{
    while (true) {
        judge();
        system("cls");
        cout << "         TIC TAC TOE GAME (2 PLAYERS)        " << endl;
        cout << "---------------------------------------------" << endl;
        cout << " Turn: " << turn << "                     Total Moves: " << moves << endl;
        cout << "---------------------------------------------" << endl;
        show_board();
        cout << "---------------------------------------------" << endl;

        cout << "( " << turn << " ) Which area do you want to put it? " << endl;
        for (int i = 0; i < 3; i ++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'O' || board[i][j] != 'X')
                {
                    cout << " " << board[i][j] << " ";
                }
            }
            cout << endl;
        }

        cout << "? "; cin >> option;

        system("cls");

        switch (option)
        {
            case 1: { row = 0; column = 0; } break;
            case 2: { row = 0; column = 1; } break;
            case 3: { row = 0; column = 2; } break;
            case 4: { row = 1; column = 0; } break;
            case 5: { row = 1; column = 1; } break;
            case 6: { row = 1; column = 2; } break;
            case 7: { row = 2; column = 0; } break;
            case 8: { row = 2; column = 1; } break;
            case 9: { row = 2; column = 2; } break;
            default: cout << "ERROR" << endl;
                     Sleep(2000);
        }

        if (board[row][column] == 'O' || board[row][column] == 'X')
        {
            cout << "This area is already used" << endl;
            Sleep (1000);
        }
        else {
            board[row][column] = turn;
            moves ++;
            if (turn == 'X')
                turn = 'O';
            else if (turn == 'O')
                turn = 'X';

        }
    }

}
