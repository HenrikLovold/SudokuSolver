//
//  square.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include "square.hpp"
#include <vector>
#include "element.hpp"

Square::Square(int num) {
    this->num = num;
    this->elements = new std::vector<Element>();
}

Square::~Square() {
    
}

void Square::addElement(Element e) {
    return;
}

int Square::getNumber()
{
    return this->num;
}
