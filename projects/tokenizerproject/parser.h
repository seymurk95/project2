
#ifndef PARSER_H
#define PARSER_H
#include "tokenizer.h"
#include <memory>
#include "helper.h"
#include <map>


class JSONParser{
private:
  std::fstream file;
  std::shared_ptr<JSON::JSON_NODE> root;
  std::unique_ptr<JSON::JSON_NODE> current;
  Tokenizer tokenizer;
public:
  JSONParser(const std::string filename): tokenizer(filename){}
  void parse();
  std::shared_ptr<JSON::JSON_NODE> parseObject();
  std::shared_ptr<JSON::JSON_NODE> parseString();
  std::shared_ptr<JSON::JSON_NODE> parseNumber();
  std::shared_ptr<JSON::JSON_NODE> parseList();
  std::shared_ptr<JSON::JSON_NODE> parseBoolean();
  std::shared_ptr<JSON::JSON_NODE> parseNull();

};

#endif PARSER_H