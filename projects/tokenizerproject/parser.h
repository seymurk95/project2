//
// Created by User on 01.03.2025.
//

#ifndef PARSER_H
#define PARSER_H
#include "tokenizer.h"
#include <memory>

class JSONParser{
private:
  std::fstream file;
  std::shared_ptr<JSON::JSONNode> root;
  std::unique_ptr<JSON::JSONNode> current;
  Tokenizer tokenizer;
public:
  JSONParser(const std::string fileName): tokenizer(fileName){}
  void parse();
  std::shared_ptr<JSON::JSONNode> parseObject();
  std::shared_ptr<JSON::JSONNode> parseString();
  std::shared_ptr<JSON::JSONNode> parseNumber();
  std::shared_ptr<JSON::JSONNode> parseList();
  std::shared_ptr<JSON::JSONNode> parseBoolean();
  std::shared_ptr<JSON::JSONNode> parseNull();
};
#endif //PARSER_H