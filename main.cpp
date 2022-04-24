#include "SudokuSolver.h"
#include <chrono>

using namespace std;

int main() {

  auto start = chrono::high_resolution_clock::now();
  
  SudokuSolver s;

  s.readPuzzle();

  s.run();

  s.printPuzzle();

  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

  cout << "\nExecution Time: " << duration.count() << '\n';
  
  return 0;
}