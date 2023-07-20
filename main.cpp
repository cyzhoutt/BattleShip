#include <iostream>
#include "board.h"
#include "inputValidation.h"
#include <array>
#include <map>
#include <fstream>
#include "player.h"
#include "game.h"
#include "helper.h"
#include <memory>


int main(int argc, char* argv[]) {
  std::ifstream inFile;
//  int userRowPoint;
//  int userColPoint;
  char symbol;
  int len;
  std::vector<int> position;

  std::map<char, int> ship_map;

  int numRows;
  int numCols;
  int numShip;

  inFile.open(argv[1]);
  if (!inFile.is_open()) {
    return 1;
  }
  //inFile >> word;
  if (inFile) {
    inFile >> numRows;
    inFile >> numCols;
    inFile >> numShip;
    while (numShip--) {
      inFile >> symbol;
      inFile >> len;
      ship_map[symbol] = len;
    }
  }

  Board empty_board(numRows, numCols);


  // std::cout << "Player 1 please enter your name: ";
  std::string p1_name= get_valid_string("", "Player 1 please enter your name: ");
  // std::getline(std::cin, p1_name);
  std::cout << std::endl;
  empty_board.display();

  Player p1(p1_name, empty_board, ship_map);
  for (const auto& items:ship_map) {
    std::string direction = hvCheck(p1_name);
    position = numInputCheckShip(direction,items.second,empty_board, items.first, p1_name);
    p1.set_board(position[0], position[1], items.first, p1.getPBoard(), items.second, direction);
    p1.getPBoard().display();
  }

  // std::cout << "Player 2 please enter your name: ";
  std::string p2_name= get_valid_string("", "Player 2 please enter your name: ");
  // std::getline(std::cin, p2_name);
  empty_board.display();
  std::cout << std::endl;
  Player p2(p2_name, empty_board, ship_map);
  for (const auto& items:ship_map) {
    std::string direction = hvCheck(p2_name);
    position = numInputCheckShip(direction,items.second,empty_board,items.first, p2_name);
    p2.set_board(position[0], position[1], items.first, p2.getPBoard(), items.second, direction);
    p2.getPBoard().display();
  }

  int playTurn = 0;
  Game game;
  game.play(playTurn, empty_board,p1,p2);









  return 0;
 }

