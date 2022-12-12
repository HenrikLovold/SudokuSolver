//
//  reader.hpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "square.hpp"
#include "board.hpp"

class Reader {
public:
    Reader(std::string filename);
    ~Reader();
    Board* nextBoard();
private:
    int currentLine = 0;
    std::vector<std::string>* lines;
    std::ifstream* file;
    void load();
    Board* buildBoard(std::string flatboard);
};
