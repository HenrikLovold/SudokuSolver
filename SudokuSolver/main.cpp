//
//  main.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include <iostream>
#include "test.hpp"

int main(int argc, const char * argv[]) {
    uint nThreads = 1;
    if (argc > 1) {
        nThreads = (uint)atoi(argv[1]);
    }
    test(nThreads);
    return 0;
}
