#include <iostream>
#include <string>
#include "board.h"

#include <iostream>
#include "board.h"


Board::Board(int numRows, int numCols) : boardContents(numRows, std::string(numCols, '*')), blankChar('*'){

}

//Board::Board(int dimensions, char blankChar) : Board(dimensions, dimensions, blankChar) {
//
//}

int Board::getNumRows() const {
  return boardContents.size();
}

int Board::getNumCols() const {
  return boardContents.front().size();
}

void Board::display() const {
  std::cout << "  ";
  for (int i = 0; i < getNumCols(); ++i) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  int rowNum = 0;
  for (const auto& row : boardContents) {
    std::cout << rowNum << ' ';
    for (const auto& piece : row) {
      std::cout << piece << ' ';
    }
    std::cout << std::endl;
    ++rowNum;
  }
}

//void Board::placePieceAt(int row, int col, char piece) {
//  boardContents.at(row).at(col) = piece;
//}

const std::vector<std::string>& Board::getBoardContents() const {
  return boardContents;
}

const char Board::getBlankChar() const {
  return blankChar;
}

std::string Board::getCol(int colIndex) const {
  std::string theColumn;
  for (int row = 0; row < getNumRows(); ++row) {
    theColumn.push_back(at(row, colIndex));
  }
  return theColumn;
}

const char& Board::at(int row, int col) const {
  return boardContents.at(row).at(col);
}

char& Board::at(int row, int col) {
  return boardContents.at(row).at(col);
}

/*bool Board::isFull() const {
  for (const auto& row : boardContents) {
    for (const auto& piece : row) {
      if (piece == blankChar) {
        return false;
      }
    }
  }
  return true;
}*/

bool Board::isBlank(int row, int col) const {
  return at(row, col) == blankChar;
}

bool Board::inBounds(int row, int col) const {
  return between(row, 0, getNumRows() - 1) && between(col, 0, getNumCols() - 1);
}

bool between(int value, int min, int max) {
  return value >= min && value <= max;

}


