//
// Created by Chenyi Zhou on 5/11/22.
//

#include "game.h"
#include "player.h"
#include "board.h"
#include "inputValidation.h"

void Game::play(int playTurn, const Board& empty_board,Player& p1, Player& p2){
  playerTurn = playTurn;
  // createPlayers(p1,p2);
  current_player = std::make_unique<Player>(p1);
  other_player = std::make_unique<Player>(p2);
  // setTurn(players[currentPlayerTurn], players[otherPlayerTurn], playerTurn);
  while (true){
    std::vector<int> positionPlay = numInputCheck(empty_board, current_player->getName());
    if (current_player->getPBoard().at(positionPlay[0],positionPlay[1]) == 'X' or current_player->getPBoard().at(positionPlay[0],positionPlay[1]) == 'O'){
      continue;
    }
    check_one_turn(positionPlay[0],positionPlay[1]);
    current_player->getPBoard().display();
    current_player->getFBoard().display();
    std::unique_ptr<Player> p2;
    p2 = std::move(current_player);
    current_player = std::move(other_player);
    other_player = std::move(p2);
//    changeTurn(current_player, other_player);
  }
}
//void changeTurn(std::unique_ptr<Player>& p0, std::unique_ptr<Player>& p1){
//  std::unique_ptr<Player> p2;
//  p2 = std::move(p0);
//  p0 = std::move(p1);
//  p1 = std::move(p2);
//}

// void Game::setTurn(std::unique_ptr<Player>& cPlayer, std::unique_ptr<Player>& c2Player,int playerTurn) {

//   current_player=std::move(cPlayer);
//   other_player=std::move(c2Player);
//   playerTurn += 1;

// }

// void Game::createPlayers(Player p1, Player p2){
//   std::unique_ptr<Player> player1 = std::make_unique<Player>(p1);
//   std::unique_ptr<Player> player2 = std::make_unique<Player>(p2);
//   players.push_back(std::move(player1));
//   players.push_back(std::move(player2));
//   currentPlayerTurn = 0;
//   otherPlayerTurn = 1;
// //  return players;
// }

void Game::check_one_turn(int userRowPoint, int userColPoint) {
  char symbol;
  if (isShip(userRowPoint, userColPoint, *current_player)) {
    symbol = current_player->getPBoard().at(userRowPoint,userColPoint);
    current_player->getPBoard().at(userRowPoint,userColPoint) = 'X';
    current_player->getFBoard().at(userRowPoint,userColPoint) = 'X';
    current_player->getMap()[symbol] -= 1;
    if (isOneWholeShip(symbol, current_player->getMap())) {
      std::cout << current_player->getName() << " hit " << other_player->getName() <<"'s" << symbol <<" !" << std::endl;
      if (isAllShips(current_player->getMap())) {
        std::cout << current_player->getName() << " won the game!" <<std::endl;
        exit(1);
      }
    }
  } else {
    current_player->getPBoard().at(userRowPoint,userColPoint) = 'O';
    current_player->getFBoard().at(userRowPoint,userColPoint) = 'O';
  }
}



