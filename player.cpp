#include <iostream>
#include <memory>
#include <string>
#include "player.h"
#include "board.h"

//void Player::setName(std::string player_name) {
//  name = player_name;
//}

//char Player::getPiece() const {
//  return piece;
//}

void Player::set_board(int numRow, int numCol, char symbol, Board& placement_board, int len, std::string hv) {
  if (hv=="h" or hv=="H"){
    for (int i =0; i<len; ++i){
      placement_board.at(numRow, numCol+i)=symbol;
    }
  }else{
    for (int i =0; i<len; ++i){
      placement_board.at(numRow+i, numCol)=symbol;
    }
  }
}



Player::Player(std::string player_name,
               const Board& base_board,
               const std::map<char, int>& ship_map)
    : player_name(player_name),
    placement_board(base_board), firing_board(base_board),
    copied_ship_map(ship_map) {
}

const std::string Player::getName() const {
  return player_name;
}
std::map<char, int>& Player::getMap() {
  return copied_ship_map;
}
Board& Player::getPBoard() {
  return placement_board;
}
Board& Player::getFBoard() {
  return firing_board;
}







