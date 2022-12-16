//
//  test.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "test.hpp"
#include "reader.hpp"
#include "board.hpp"
#include "element.hpp"
#include "square.hpp"
#include "solver.hpp"

int test() {
    Solver s = Solver("sudoku.txt");
    unsigned int solveCounter = 0;
    while (s.hasUnsolvedBoards()) {
        if (solveCounter == 0) {
            std::cout << "Starting solving process..." << std::endl;
        }
        s.solveNext();
        solveCounter++;
        if (solveCounter % 10000 == 0) {
            std::cout << "Solved: " << solveCounter << std::endl;
        }
    }

    std::cout << "Program finished, press enter to exit." << std::endl;
    std::cin.get();
    
    return 0;
}
