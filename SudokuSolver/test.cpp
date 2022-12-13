//
//  test.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include <stdio.h>
#include "test.hpp"
#include "reader.hpp"
#include "board.hpp"
#include "element.hpp"
#include "square.hpp"

int test() {
    Reader r("sudoku.txt");
    Board* b = r.nextBoard();
    b->printBoard();

    std::cout << "Program finished, hit enter to exit." << std::endl;
    std::cin.get();
    
    return 0;
}
