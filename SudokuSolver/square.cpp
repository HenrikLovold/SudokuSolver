//
//  square.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include "square.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "element.hpp"

Square::Square(int num) {
    this->num = num;
    this->elements = new std::vector<Element>();
}

Square::~Square() {
    
}

void Square::addElement(Element e) {
    this->elements->push_back(e);
}

int Square::getNumber() {
    return this->num;
}

void Square::printInfo() {
    std::cout << "Square with number: " << this->num << std::endl;
    std::string s;
    this->elements[0][2].printValues();
}
