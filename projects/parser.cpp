#include "parser.h"
void JSONParser::parse(){
  std::string key = "";
  while(tokenizer.hasMoreTokens()){
    Token token;
    try{
      token = tokenizer.getToken();
      std::cout << token.toString() << std::endl;
      switch(token.type){
        case TOKEN::CURLY_OPEN:
          std::shared_ptr<JSON::JSONNode> parseObject = parseObject);
          parseObject -> printNode(0);
          if(!root){
            root = parseObject;
          }
          break;
          case TOKEN::STRING:
            tokenizer.rollBackToken();

      }
    }
  }
}