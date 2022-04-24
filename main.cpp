#include "SudokuSolver.h"

using namespace std;

int main() {
  
  SudokuSolver s;

  s.readPuzzle();

  s.printPuzzle();
  
  return 0;
}