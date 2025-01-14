//
//  test.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <ctime>
#include "test.hpp"
#include "reader.hpp"
#include "board.hpp"
#include "element.hpp"
#include "square.hpp"
#include "solver.hpp"

int test() {
    Solver s = Solver("sudoku.txt");
    unsigned int solveCounter = 0;
    time_t start = time(NULL); 
    s.solveAll();
    time_t run_total = time(NULL) - start;
    std::cout << "Program finished in " << run_total << "s, press enter to exit." << std::endl;
    std::cin.get();
    
    return 0;
}
