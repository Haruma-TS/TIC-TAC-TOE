#include <iostream>
#include <ctime>

using namespace std;

void drawBoard(char* spaces) {
    cout << '\n';
    cout << "     |     |     "<<'\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____ " << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____ " << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n'; 
}

void playerMove(char* spaces, char player) {
    int number;
    do {
        cout << "Enter a spot to place a marker(1-9): ";
        cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (~number > 0 || ~number < 8);
}

void computerMove(char* spaces, char computer) {
    int number;
    srand(time(NULL));

    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char* spaces, char player, char computer) {
    if (spaces[0]!= ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }else
        if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
            spaces[3] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
        }else
            if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
                spaces[6] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
            }else
                if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[0] == spaces[6]) {
                    spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
                }else
                    if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
                        spaces[1] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
                    }else
                        if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
                            spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
                        }else
                            if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
                                spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
                            }else
                                if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
                                    spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
                                }
                                else { return false; }
    return true;
}

bool checkTie(char* spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}

int main()
{
    char spaces[9];
    fill(spaces, spaces + 9, ' ');
    char player = 'X';
    char computer = 'O';
    bool running = true;


    while (running) {
        playerMove(spaces, player);
        system("cls");
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }else
            if (checkTie(spaces)) {
                running = false;
                break;
            }
        computerMove(spaces,computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else
            if (checkTie(spaces)) {
                running = false;
                break;
            }
    }
    cout << "Thanks for playing!\n";
    return 0;
}

