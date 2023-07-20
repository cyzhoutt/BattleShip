#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <vector>
#include <string>

class Board {
 public:
//  Board() {
//    numRows = ;
//    numCols = ;
//  };
  Board(int numRows, int numCols);
//  Board(int dimensions, char blankChar);


  int getNumRows() const;
  int getNumCols() const;

  void display() const;
//  void placePieceAt(int row, int col, char piece);
  const std::vector<std::string>& getBoardContents() const;
  //std::vector<std::string>& getBoardContents();
  const char getBlankChar() const;
  char& at(int row, int col);
  const char& at(int row, int col) const;
//  bool isFull() const;

  bool isBlank(int row, int col)const;
  bool inBounds(int row, int col) const;


  std::string getCol(int colIndex) const;

 private:
  std::vector<std::string> boardContents;
  const char blankChar;
  int numRows;
  int numCols;
};
bool between(int value, int min, int max);

#endif //BATTLESHIP_BOARD_H