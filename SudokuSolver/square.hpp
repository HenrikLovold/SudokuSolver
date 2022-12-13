//
//  square.hpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#pragma once

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

class Element;

class Square {
public:
    Square(int num);
    ~Square();
    void addElement(Element e);
    int getNumber();
private:
    int num;
    std::vector<Element>* elements;
};
