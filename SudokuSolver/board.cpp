//
//  board.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include "board.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "element.hpp"

Board::Board(Square*** squares) {
    this->squares = squares;
    this->elements = new std::vector<Element>();
}

Board::~Board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            delete this->squares[i][j];
        }
    }
    delete this->squares;
    
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

void Board::generateElements() {

}
