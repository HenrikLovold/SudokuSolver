//
//  reader.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include "reader.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "square.hpp"
#include "board.hpp"

Reader::Reader(std::string filename) {
    this->file = new std::ifstream(filename, std::ifstream::in);
    this->lines = new std::vector<std::string>();
    this->load();
}

void Reader::load() {
    std::string line;
    while (std::getline(*this->file, line)) {
        this->lines->push_back(line);
    }
}

Board* Reader::buildBoard(std::string flatboard) {
    Square*** board = new Square**[9];
    int symNum = 0;
    for (int i = 0; i < 9; i++) {
        board[i] = new Square*[9];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = new Square(flatboard[symNum] - '0');
            symNum++;
        }
    }
    Board* finished = new Board(board);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    
    return finished;
}

Board* Reader::nextBoard() {
    this->currentLine++;
    
    return nullptr;
}

Reader::~Reader() {
    
}
