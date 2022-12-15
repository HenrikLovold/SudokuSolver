//
//  solver.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include "solver.hpp"
#include <string>
#include <vector>
#include "reader.hpp"

Solver::Solver(std::string filename) {
	this->reader = new Reader(filename);
	this->boards = new std::vector<Board*>();
	this->solved = new std::vector<Board*>();
	this->currentBoardNumber = 0;
}

Solver::~Solver() {
	delete this->boards;
}

void Solver::solveNext() {
	Board* currentBoard = this->reader->nextBoard();
	currentBoard->solve(0);
	delete currentBoard;
}

bool Solver::hasUnsolvedBoards() {
	return this->reader->hasNext();
}

void Solver::loadBoards() {
	std::cerr << "Solver.loadBoards() is deprecated" << std::endl;
	Board* next = this->reader->nextBoard();
	while (next != nullptr) {
		this->boards->push_back(next);
		next = this->reader->nextBoard();
	}
	delete this->reader;
}
