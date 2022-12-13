//
//  element.hpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#pragma once

#include <stdio.h>
#include "square.hpp"

class Element {
public:
    Element(Square** squares);
    ~Element();
private:
    Square** squares;
};
