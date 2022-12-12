//
//  board.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include "board.hpp"
#include <string>
#include <iostream>

Board::Board(Square*** squares) {
    this->squares = squares;
}

Board::~Board() {
    
}

void Board::printBoard() {
    std::cout << "Board:" << std::endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << this->squares[i][j]->getNumber();
        }
        std::cout << std::endl;
    }
}