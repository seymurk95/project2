#include "parser.h"
void JSONParser::parse(){
  std::string key = "";
  while(tokenizer.hasMoreTokens()){
    Token token;
    try {
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
        std::shared_ptr<JSON::JSONNode>parseString = parseString;
        if(!root) {
          root = parseString;
        }
        break;
        case TOKEN::NUMBER:
          tokenizer.rollBackTokens();
        std::shared_ptr<JSON::JSONNode>parseNumber = parseNumber;
        if(!root) {
          root = parseNumber;
        }
        break;
        case TOKEN::BOOLEAN:
          tokenizer.rollBackTokens();
        std::shared_ptr<JSON::JSONNode>parseBoolean = parseBoolean;
        break;
      }
    } catch(std::logic_error) {
      break;
    }
  }
}

std::shared_ptr <JSON::JSONNode> ::parseList() {
  std::cout<<"parse list"<<std::endl;
  std::shared_ptr <JSON::JSONNode> node=std::make_shared<JSON::JSONNode>()>();
  JSON::JSONlist *list = new JSON::JSONList();
  bool hasCompleted= false;
  while(!hasCompleted) {
    if(!tokenizer.hasMoreTokens()) {
      throw std::logic_error("tokenizer.hasMoreTokens()");
    }else {
      Token nextToken=tokenizer.getToken();
      std::shared_ptr<JSON::JSONNode> node;
      switch(nextToken.type) {
        case TOKEN::ARRAY_OPEN:
          node=parseList();
        break;
        case TOKEN::ARRAY_CLOSE:
          node=parseList();
        break;
        case TOKEN::CURLY_OPEN:
          node=parseList();
        break;
        case TOKEN::CURLY_CLOSE:
          node=parseList();
        break;
        case TOKEN::STRING:
          tokenizer.rollBackToken();
        node = parseString();
        break;
        case TOKEN::NUMBER:
          tokenizer.rollBackToken();
        node = parseNumber();
        break;
        case TOKEN::BOOLEAN:
          tokenizer.rollbackToken();
        node= parseBoolean();
        break;
        case TOKEN::NULL_TYPE:
          node = parseNull();
        break;
      }
      list->push_back(node);
      nextToken = tokenizer.getToken();
      if(nextToken.type == TOKEN::ARRAY_CLOSE) {
        hasCompleted= true;
      }
    }
  }
  node->setlist(list);
  return node;
}

std::shared_ptr<JSON::JSONnode> JSONParser::parseObject() {
  std::cout<<"parse object"<<std::endl;
  std::shared_ptr<JSON::JSONNode> node= std::make_shared<JSON::JSONNode>();
  JSON::JSONObject * keyobjectmap=new JSON::JSONObject();
  bool hasCompleted= false;
  while(!hasCompleted) {
    if(tokenizer.hasMoreTokens()) {
      Token nextToken= tokenizer.getToken();
      std::string key= nextToken.value;
      std::cout<<"key: "<<std::endl;
      tokenizer.getToken();
      nextToken=tokenizer.getToken();
      std::shared_ptr<JSON::JSONNode> node;
      switch(nextToken.type) {
        case TOKEN::STRING:
          tokenizer.rollBackToken();
        (*keyobjectmap)[key]=parseString();
        break;
        case TOKEN::ARRAY_OPEN:
          (*keyobjectmap)[key]=parseList();
        break;
        case TOKEN::NUMBER:
          tokenizer.rollBackToken();
        (*keyobjectmap)[key]=parseNumber();
        break;
        case TOKEN::CURLY_OPEN:
          (*keyobjectmap)[key]=parseList();
        break;
        case TOKEN::BOOLEAN:
          tokenizer.rollBackToken();
        (*keyobjectmap)[key]=parseBoolean();
        break;
        case TOKEN::NULL_TYPE:
          (*keyobjectmap)[key]=parseNull();
        break;
      }
      nextToken = tokenizer.getToken();
      if(nextToken.type == TOKEN::ARRAY_CLOSE) {
        hasCompleted= true;
        break;
      }
    }else {
      throw std::logic_error("No more tokens");
    }
  }
  node->setobject(keyobjectmap);
  return node;
}

std::shared_ptr<JSON::JSONNode> parseString() {
  std::cout<<"parse string"<<std::endl;
  std::shared_ptr<JSON::JSONNode> node= std::make_shared<JSON::JSONNode>();
  Token token=tokenizer.getToken();
  std::string *sValue=new std::string(token.value);
  node -> setstring(*sValue);
  return node;

}

std::shared_ptr<JSON::JSONNode> parseNumber() {
  std::cout<<"parse number"<<std::endl;
  std::shared_ptr<JSON::JSONNode> node= std::make_shared<JSON::JSONNode>();
  Token token=tokenizer.getToken();
  std::string value=nextToken.value;
  std::cout<<"value: "<<std::endl;
  float fvalue=std::stof(value);
  node -> setnumber(fvalue);
  return node;
}