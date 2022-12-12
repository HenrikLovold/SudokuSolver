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
    this->filename = filename;
    this->lines = new std::vector<std::string>();
    this->load();
}

void Reader::load() {
    std::string line;
    std::ifstream file = std::ifstream(this->filename, std::ifstream::in);
    if (!file) {
        std::cerr << "Unable to find file." << std::endl;
    }
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        this->lines->push_back(line);
    }
    file.close();
}

Board* Reader::buildBoard(std::string flatboard) {
    Square*** squares = new Square**[9];
    int symNum = 0;
    for (int i = 0; i < 9; i++) {
        squares[i] = new Square*[9];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            squares[i][j] = new Square(flatboard[symNum] - '0');
            symNum++;
        }
    }
    return new Board(squares);
}

Board* Reader::nextBoard() {    
    return this->buildBoard(this->lines->at(this->currentLine++));
}

Reader::~Reader() {
    delete this->lines;
}
