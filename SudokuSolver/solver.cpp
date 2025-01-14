//
//  solver.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include <string>
#include <vector>
#include <thread>
#include "reader.hpp"
#include "solver.hpp"

Solver::Solver(std::string filename, uint nThreads) {
	this->reader = new Reader(filename);
	this->boards = new std::vector<Board*>();
	this->solved = new std::vector<Board*>();
	this->currentBoardNumber = 0;
	this->nLines = this->reader->getNLines();
	this->nThreads = nThreads;
}

Solver::~Solver() {
	delete this->boards;
}

void Solver::solveThreadMain() {
	while (this->currentBoardNumber < this->nLines) {
		Board* solveBoard = this->reader->nextBoard();
		solveBoard->solve(0);
		this->currentBoardNumber++;
		if (this->currentBoardNumber % 10000 == 0) {
			std::cout << "Solved #" << this->currentBoardNumber << std::endl;
		}
		delete solveBoard;
	}
}

void Solver::solveAll() {
	std::vector<std::thread> threads;
	for (uint i = 0; i < this->nThreads; i++) {
		threads.push_back(std::thread([this] { this->solveThreadMain(); }));
	}
	for (uint i = 0; i < this->nThreads; i++) {
		threads[i].join();
	}
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
