//
//  solver.hpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include "reader.hpp"
#include "board.hpp"

class Solver {
public:
    Solver(std::string filename);
    ~Solver();
    void solveAll();
    bool hasUnsolvedBoards();
    void solveThreadMain();
private:
    Reader* reader;
    std::vector<Board*>* boards;
    std::vector<Board*>* solved;
    int currentBoardNumber;
    
    void loadBoards();
};
