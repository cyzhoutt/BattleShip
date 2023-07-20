//
// Created by Chenyi Zhou on 5/11/22.
//

#ifndef BATTLESHIP__GAME_H_
#define BATTLESHIP__GAME_H_
#include "player.h"
#include <memory>


class Game{
 public:
//  Game(std::unique_ptr<Player>& cPlayer, std::unique_ptr<Player>& c2Player):current_player(std::move(cPlayer)),other_player(std::move(c2Player)) {}
// Game(std::unique_ptr<Player> cPlayer, std::unique_ptr<Player> c2Player):current_player(std::move(cPlayer)),other_player(std::move(c2Player)) {}
  void play(int playerTurn, const Board& empty_board,Player& p1, Player& p2);
  void setTurn(std::unique_ptr<Player>& cPlayer, std::unique_ptr<Player>& c2Player, int playerTurn);
  void createPlayers(Player p1, Player p2);

  void check_one_turn(int userRowPoint, int userColPoint);
//  void new_game();
  bool isShip(int userRowPoint, int userColPoint, Player player);
  bool isOneWholeShip(char symbol, const std::map<char, int>& map);
  bool isAllShips(const std::map<char, int>& map);
//  const Player& changeTurn();
  void changeTurn(std::unique_ptr<Player>p0, std::unique_ptr<Player>p1);

 private:
  std::unique_ptr<Player> current_player;
  std::unique_ptr<Player> other_player;
  std::vector<std::unique_ptr<Player>> players;
  int playerTurn;
  int currentPlayerTurn;
  int otherPlayerTurn;

};
#endif //BATTLESHIP__GAME_H_
