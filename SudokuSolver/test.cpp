//
//  test.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include <stdio.h>
#include "reader.hpp"
#include "board.hpp"
#include "element.hpp"
#include "square.hpp"

int test() {
    Reader r("sudoku.txt");
    Board* b = r.nextBoard();
    
    return 0;
}
