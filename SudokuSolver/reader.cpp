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
    try {
        while (std::getline(file, line)) {
            this->lines->push_back(line);
        }
    }
    catch (std::out_of_range){
        std::cerr << "Memory error in load, the file probably couldn't be read";
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
    try {
        if (this->currentLine < this->lines->size()) {
            return this->buildBoard(this->lines->at(this->currentLine++));
        }
        return nullptr;
    }
    catch (std::out_of_range) {
        std::cerr << "Could not fetch next board and got an std::out_of_range exception." << std::endl;
        std::cerr << "Press enter to exit (code will be 1)." << std::endl;
        std::cin.get();
        exit(1);
    }
}

Reader::~Reader() {
    delete this->lines;
}
