//
//  element.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include "element.hpp"
#include "square.hpp"
#include <iostream>
#include <string>

Element::Element(Square** squares) {
	this->squares = squares;
}

Element::~Element() {

}
