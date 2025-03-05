#include "tokenizer.h"
Tokenizer::Tokenizer(std::string filename){
  file.open(filename,std::ios::in);
  if(!file.open()){
    std::cerr<<"Error in opening file "<<std::endl;
  }
}
auto Tokenizer::getWithoutWhiteSpace() {
  char c = ' ';
  while (c == ' ' ||  c == '\n') {
    file.get(c);
    if (c == ' ' || c == '\n') {
      throw std::logic_error("Tokens over");
    }else if(!file.good()){
      return c;
    }
  }
  return c;
}

void Tokenizer::rollBackToken() {
  if(file.eof()){
    file.clear();
  }
  file.seekg(prevPos);
}

auto Tokenizer::getToken() {
  char c ;
  if(file.eof()){
    std::cout<<"Out of tokens!"<<std::endl;
  }
  prevPos = file.tellg();

  c = getWithoutWhiteSpace();

  Token token;

  if(c == '"'){
    token.type = TOKEN::STRING;
    token.value = "";
    file.get (c);
    while(c!= '"'){
      token.value += c;
      file.get (c);
    }

  }else if (c == '{'){
    token.type = TOKEN::CURLY_OPEN;
  }else if (c == '}'){
    token.type = TOKEN::CURLY_CLOSE;
  }else if (c=='-' || (c>='0' && c<='9')){
    token.type = TOKEN::NUMBER;
    token.value = "";
    token.value += c;
    std::streampos prevCharPos = file.tellg();
    while((c=='-') || (c>='0' && c<='9')|| c== '.'){
      prevCharPos = file.tellg();
      file.get(c);

      if(file.eof()){
        break;

      }else{
        file.seekg(prevCharPos);
      }
    }
  }else if(c == 'f'){
    token.type = TOKEN::BOOLEAN;
    token.value = "False";
    file.seekg(4, std::ios_base::cur);

  }else if(c == 't'){
    token.type = TOKEN::BOOLEAN;
    token.value = "True";
    file.seekg(3, std::ios_base::cur);
  }else if(c == 'n'){
    token.type = TOKEN::NULL_TYPE;
    file.seekg(3, std::ios_base::cur);
  }else if(c == '['){
    token.type = TOKEN::ARRAY_OPEN;
  }else if(c == ']'){
    token.type = TOKEN::ARRAY_CLOSE;
  }else if(c == ':'){
    token.type = TOKEN::COLON;
  }else if(c == ','){
    token.type = TOKEN::COMMA;
  }
}

auto Tokenizer::hasMoreTokens() {
  return !file.eof();
}
std::string Token::toString(){
  switch(type){
    case TOKEN::CURLY_OPEN:
      return "curlyOpen";
    case TOKEN::CURLY_CLOSE:
      return "curlyClose";
    case TOKEN::COLON:
      return "colon";
    case TOKEN::NUMBER:
      return "number";
    case TOKEN::STRING:
      return "string";
    case TOKEN::ARRAY_OPEN:
      return "arrayOpen";
    case TOKEN::ARRAY_CLOSE:
      return "arrayClose";
    case TOKEN::COMMA:
      return "comma";
    case TOKEN::BOOLEAN:
      return "boolean";
    case TOKEN::NULL_TYPE:
      return "nullType";
  }
}
