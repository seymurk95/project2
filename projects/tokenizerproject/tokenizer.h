//
// Created by User on 01.03.2025.
//

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <fstream>
#include <iostream>
enum class TOKEN{
  CURLY_OPEN,
  CURLY_CLOSE,
  COLON,
  STRING,
  NUMBER,
  ARRAY_OPEN,
  ARRAY_CLOSE,
  COMMA,
  BOOLEAN,
  NULL_TYPE
  };
struct Token{
  std::string value;
  TOKEN type;
  std::string toString();
};
class Tokenizer{
private:
  std::fstream file;
  size_t prevPos;
public:
  Tokenizer(std::string fileName);
  auto getWithoutSpace();
  Token getToken();
  bool hasMoreTokens();
  void rollBackToken();
};



#endif //TOKENIZER_H