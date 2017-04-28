#include <iostream>
#include "../include/gameboard.h"
#include "util.h"

using namespace std;

int main() {
    auto gameboard = new Gameboard(9);
/*
    while (!gameboard->isSolved()) {
        int col, row, val;
        cout << "Please enter your next move:" << endl;
        cout << "Column:" << endl;
        cin >> col;
        cout << "Row:" << endl;
        cin >> row;
        cout << "Value:" << endl;
        cin >> val;
        if (gameboard->nextMove(col, row, val)) {
            gameboard->print();
            cout << endl;
            gameboard->printClasses();
        } else {
            cout << "Invalid move, try again pls" << endl;
        }
    }

    */

    gameboard->nextMove(4, 4, 1);
    gameboard->nextMove(4, 5, 3);

    while(gameboard->evaluateNext()) {
        printBoard(gameboard->get2DArray(), 9);
        printBoard(gameboard->getClasses(), 9);
    }

    return 0;
}

