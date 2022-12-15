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
    delete this->elements;
}

void Square::addElement(Element e) {
    this->elements->push_back(e);
}

int Square::getNumber() {
    return this->num;
}

void Square::setNumber(int num) {
    this->num = num;
}

bool Square::checkValid(int num) {
    for (int i = 0; i < this->elements->size(); i++) {
        if (!this->elements->at(i).checkValid(num)) {
            return false;
        }
    }
    return true;
}

void Square::printInfo() {
    std::cout << "Square with number: " << this->num << std::endl;
    std::string s;
    this->elements[0][2].printValues();
}
