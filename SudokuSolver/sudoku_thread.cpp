
#include <thread>
#include "sudoku_thread.hpp"

SudokuThread::SudokuThread() {
    this->isAvailable = true;
    this->currentBoard = nullptr;
}

SudokuThread::~SudokuThread() {

}

inline void start() {
    
}

void SudokuThread::newBoard(Board* board) {
    this->currentBoard = board;
}

void SudokuThread::run() {
    this->isAvailable = false;
    this->currentBoard->solve(0);
    delete this->currentBoard;
    this->isAvailable = true;
}
