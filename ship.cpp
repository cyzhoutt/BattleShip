//
// Created by Chenyi Zhou on 5/8/22.
//
#include <iostream>
#include <vector>
#include <map>
#include "board.h"
#include "player.h"
#include "game.h"
//void add_to_map(char symbol, int len, std::map<char, int>&map) {
//  map[symbol] = len;
//}

bool Game::isShip(int userRowPoint, int userColPoint, Player player) {
  return player.getPBoard().at(userRowPoint, userColPoint) != '*';
}

bool Game::isOneWholeShip(char symbol, const std::map<char, int>& map) {
  //change symbol to a ship
  if (map.at(symbol) == 0) {
    return true;
  }
  else{
    return false;
  }
}
bool Game::isAllShips(const std::map<char, int>& map) {
  for (const auto& items : map) {
    if (items.second != 0) {
      return false;
    }
  }
  return true;
}
