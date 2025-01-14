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
    bool hasNext();
    int getNLines();
private:
    int currentLine = 0;
    std::string filename;
    std::vector<std::string>* lines;
    void load();
    Board* buildBoard(std::string flatboard);
};
