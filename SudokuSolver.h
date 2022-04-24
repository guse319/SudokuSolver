#include <vector>
#include <map>
#include <iostream>

using namespace std;

class SudokuSolver {

public:

  SudokuSolver() {
    return;
  }

  void readPuzzle() {
    int in;
    puzzle.resize(9);
    for(int i = 0; i < 9; ++i) {
      puzzle[i].resize(9);
      for(int j = 0; j < 9; ++j) {
        cin >> in;
        puzzle[i][j].value = in;
        if(i < 3 && j < 3) puzzle[i][j].box = 0;
        else if(i < 3 && j < 6) puzzle[i][j].box = 1;
        else if(i < 3) puzzle[i][j].box = 2;
        else if(i < 6 && j < 3) puzzle[i][j].box = 3;
        else if(i < 6 && j < 6) puzzle[i][j].box = 4;
        else if(i < 6) puzzle[i][j].box = 5;
        else if(j < 3) puzzle[i][j].box = 6;
        else if(j < 6) puzzle[i][j].box = 7;
        else puzzle[i][j].box = 8;
      }
    }
  }

  void printPuzzle() {
    for(int i = 0; i < 9; ++i) {
      for(int j = 0; j < 9; ++j) {
        cout << puzzle[i][j].box << ' ';
      }
      cout << '\n';
    }
  }

private:

  void initSolve() {

    boxes.resize(9);
    rows.resize(9);
    cols.resize(9);
    
    for(int i = 0; i < 9; ++i) {
      for(int j = 0; j < 9; ++j) {
        if(puzzle[i][j].value > 0) {
          boxes[puzzle[i][j].box].insert(pair<int, int>(puzzle[i][j].value, 0))
          rows[i].insert(pair<int, int>(puzzle[i][j].value, 0));
          cols[j].insert(pair<int, int>(puzzle[i][j].value, 0));
        }
      }
    }
  }

  void ruleBox() {

  }

  struct Square {
    int box;
    int value;
    map<int, int> potentials = { {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}, };
  };

  vector<map<int, int>> boxes;
  vector<map<int, int>> rows;
  vector<map<int, int>> cols;

  vector<vector<Square>> puzzle;

};