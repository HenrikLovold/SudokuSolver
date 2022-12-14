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
#include "square.hpp"

Board::Board(Square*** squares) {
    this->squares = squares;
    this->elements = new std::vector<Element>();
    this->generateElements();
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

Square* Board::getSquareAt(int x, int y) {
    return this->squares[x][y];
}

void Board::generateElements() {
    Square** currRow = new Square*[9];
    Square** currCol = new Square*[9];
    unsigned int cnt = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            currRow[cnt] = this->squares[i][j];
            currCol[cnt] = this->squares[j][i];
            cnt++;
        }
        this->elements->push_back(Element(currRow));
        this->elements->push_back(Element(currCol));
        currRow = new Square*[9];
        currCol = new Square*[9];
        cnt = 0;
    }
    delete currRow;
    delete currCol;
    std::cout << "finished rows and columns" << std::endl;
    for (int offsetX = 0; offsetX < 9; offsetX += 3) {
        for (int offsetY = 0; offsetY < 9; offsetY += 3) {
            Square** box = new Square*[9];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    box[(i*3) + j] = this->squares[i + offsetX][j + offsetY];
                }
            }
            this->elements->push_back(Element(box));
        }
    }

}
