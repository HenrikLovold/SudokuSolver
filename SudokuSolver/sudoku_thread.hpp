#pragma once

#include <thread>
#include "board.hpp"

class SudokuThread : std::thread {
    public:
        SudokuThread();
        ~SudokuThread();
        void run();
        void newBoard(Board* board);
        inline void start();
        bool isAvailable;
    private:
        Board* currentBoard;
};