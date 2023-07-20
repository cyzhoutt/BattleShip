#include "inputValidation.h"
#include "board.h"
#include <iostream>
#include <string>
#include <iosfwd>
#include <vector>
#include <sstream>

std::vector<int> get_2_valid_int(const std::string& prompt) {
  std::string line;
  std::vector<int> num;
  // std::getline(std::cin, line);
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, line); //grabs the entire line
    std::stringstream line2parse(line);
    int num1;
    int num2;
    line2parse >> num1 >> num2;
    if (line2parse) { //if I was able to read the number
      std::string what_is_left;
      line2parse >> what_is_left;
      if (not line2parse) { //if there is nothing left we will fail to read it
        num.push_back(num1);
        num.push_back(num2);
        return num;
      }
    }
  }
}

std::string get_valid_string(const std::string& name, const std::string& prompt) {
  std::string line;
  // std::getline(std::cin,line);
  while (true) {
    std::cout << name << prompt;
    std::getline(std::cin, line); //grabs the entire line
    std::stringstream line2parse(line);
    std::string word;
    line2parse >> word;
    if (line2parse) { //if I was able to read the number
      std::string what_is_left;
      line2parse >> what_is_left;
      if (not line2parse) { //if there is nothing left we will fail to read it
        return word;
      }
    }
  }
}

bool shipLocCheck(int num1, int num2, const std::string& hv, int len, Board player_placement_board) {
  if (hv == "h" or hv == "H") {
    for (int i = 0; i < len; i++) {
      if (player_placement_board.inBounds(num1, num2 + i) && player_placement_board.at(num1, num2)=='*'){
        continue;
      }else{
        return false;
      }
    }
    return true;
  } else {
    if (hv == "v" or hv == "V") {
      for (int i = 0; i < len; i++) {
        if (player_placement_board.inBounds(num1+i, num2) && player_placement_board.at(num1, num2)=='*'){
          continue;
        }else{
          return false;
        }
        }
      }
      return true;
    }
}

std::vector<int> numInputCheckShip(const std::string& hv, int len, const Board& player_placement_board, char symbol, std::string name) {
  std::vector<int> numInput;
  std::string sym(1, symbol);
  std::string prompt = name + ", enter the row and column you want to place " + sym + ", which is " + std::to_string(len) + " long, at with a space in between row and col: ";
//  numInput();
  do {
    numInput = get_2_valid_int(prompt);
  } while (!(numInput.size() == 2) && (shipLocCheck(numInput[0], numInput[1], hv, len, player_placement_board)));
  return numInput;
}

std::vector<int> numInputCheck(const Board& board, std::string name) {
  std::vector<int> numInput;
  std::string prompt = name + ", where would you like to fire?\n Enter your attack coordinate in the form row col: ";
  do {
    numInput = get_2_valid_int(prompt);
  } while (!(board.inBounds(numInput[0], numInput[1])&&(numInput.size() == 2)));
  return numInput;
}

std::string hvCheck(const std::string& name) {
  std::string hv;
  do {
    hv = get_valid_string(name," , do you want to place H horizontally or vertically?\nEnter h for horizontal or v for vertical\nYour choice: ");
  } while (!(hv == "h" or hv == "v" or hv == "H" or hv == "V"));
  return hv;
}
