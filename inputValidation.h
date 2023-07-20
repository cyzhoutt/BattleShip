#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
  #include "inputValidation.h"
  #include "board.h"
  #include <iostream>
  #include <string>
  #include <iosfwd>
  #include <vector>

std::vector<int> get_2_valid_int(const std::string& prompt);
//std::vector<int> numInputCheck();
bool shipLocCheck(int num1, int num2, const std::string& hv, int len, Board board);
std::vector<int> numInputCheck(const Board& board, std::string name);
std::string hvCheck(const std::string& name);
std::vector<int> numInputCheckShip(const std::string& hv, int len, const Board& player_placement_board, char symbol, std::string name);
std::string get_valid_string(const std::string& name, const std::string& prompt);

#endif