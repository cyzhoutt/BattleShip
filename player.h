//
// Created by Chenyi Zhou on 5/8/22.
//

#ifndef BATTLESHIP__PLAYER_H_
#define BATTLESHIP__PLAYER_H_

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <map>
#include "board.h"
#include <string>
//using namespace std;

//namespace Battleship {

class Player {
 public:
  Player(std::string player_name,
         const Board& base_board,
         const std::map<char, int>& ship_map);

  void set_board(int numRow, int numCol, char symbol, Board& placement_board, int len, std::string hv);

  const std::string getName() const;

  std::map<char, int>& getMap();

  Board& getPBoard();

  Board& getFBoard();


 private:
  std::string player_name;
  std::map<char, int> copied_ship_map;
  Board placement_board;
  Board firing_board;


};
#endif //BATTLESHIP__PLAYER_H_
