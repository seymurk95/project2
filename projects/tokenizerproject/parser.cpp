#include "parser.h"
#include "tokenizer.h"

void JSONParser::parse(){

    std::string key="";

    while(tokenizer.hasMoreTokens()){

        Token token;

        try {

        token = tokenizer.getToken();

        std::cout<<token.toString()<<"\n";

        switch(token.type){

            case TOKEN::CURLY_OPEN:

                std::shared_ptr<JSON::JSON_NODE> parsedObject=parseObject();

                parsedObject->printNode(0);

                if(!root){

                    root=parsedObject;

                }

            break;

            case TOKEN::ARRAY_OPEN:

                std::shared_ptr<JSON::JSON_NODE> parsedList=parseList();

                if(!root){

                    root=parsedList;

                }

                break;

            case TOKEN::STRING:

            tokenizer.rollBackToken();

            std::shared_ptr<JSON::JSON_NODE> parsedString = parseString();

            if(!root) {

                root = parsedString;

            }

            break;

            case TOKEN::NUMBER:

                tokenizer.rollBackToken();

                std::shared_ptr<JSON::JSON_NODE> parsedNumber=parseNumber();

                if(!root){

                    root=parsedNumber;

                }

                break;

            case TOKEN::BOOLEAN:

                tokenizer.rollBackToken();

                std::shared_ptr<JSON::JSON_NODE> parsedBoolean=parseBoolean();

                break;


        }

        }

        catch (std::logic_error e){

        break;

    }

    }


}

std::shared_ptr<JSON::JSON_NODE> parseList() {

    std::cout << "Parse list\n";

    std::shared_ptr<JSON::JSON_NODE> node = std::make_shared<JSON::JSON_NODE>();

    JSON::JSONList *list = new JSON::JSONList;

    bool hasCompleted = false;

    while (!hasCompleted) {

        if (!tokenizer.hasMoreTokens()) {

            throw std::logic_error("No more tokens");


        } else {

            Token nextToken = tokenizer.getToken();

            std::shared_ptr<JSON::JSON_NODE> node;

            switch (nextToken.type) {

                case TOKEN::ARRAY_OPEN:

                    node = parseList();

                    break;

                case TOKEN::CURLY_OPEN:

                    node = parseObject();

                    break;

                case TOKEN::STRING:

                    tokenizer.rollBackToken();

                    node=parseString();

                    break;

                case TOKEN::NUMBER:

                    tokenizer.rollBackToken();

                    node=parseNumber();

                    break;

                case TOKEN::BOOLEAN:

                    tokenizer.rollBackToken();

                    node=parseBoolean();

                    break;

                case TOKEN::NULL_TYPE:

                    node=parseNull();

                    break;

            }

            list->push_back(node);

            nextToken=tokenizer.getToken();

            if(nextToken.type==TOKEN::ARRAY_CLOSE){

                hasCompleted=true;

        }

}}

    node->setList(list);

    return node;

};

std::shared_ptr<JSON::JSON_NODE> parseObject(){

    std::cout<<"parsing object";

    std::shared_ptr<JSON::JSON_NODE> node=std::make_shared<JSON::JSON_NODE>();

    JSON::JSONObject *keyObjectMap=new JSON::JSONObject();

    bool hasCompleted=false;

    while(!hasCompleted) {

        if (tokenizer.hasMoreTokens()) {

            Token nextToken = tokenizer.getToken();

            std::string key = nextToken.value;

            std::cout << key << "\n";

            nextToken = tokenizer.getToken();

            std::shared_ptr<JSON::JSON_NODE> node;

            switch (nextToken.type) {

                case TOKEN::STRING:

                    tokenizer.rollBackToken();

                    (*keyObjectMap)[key] = parseString();

                    break;

                case TOKEN::ARRAY_OPEN:

                    (*keyObjectMap)[key] = parseList();

                    break;

                case TOKEN::NUMBER:

                    tokenizer.rollBacktoken();

                    (*keyObjectMap)[key] = parseNumber();

                    break;

                case TOKEN::CURLY_OPEN:

                    (*keyObjectMap)[key] = parseObject();

                    break;

                case TOKEN::BOOLEAN:

                    tokenizer.rollBackToken();

                    (*keyObjectMap)[key] = parseBoolean();

                    break;

                case TOKEN::NULL_TYPE:

                    (*keyObjectMap)[key] = parseNull();

                    break;

            }

            nextToken = tokenizer.getToken();

            if (nextToken.type == TOKEN::CURLY_CLOSE) {

                hasCompleted = true;

                break;

            } else

                throw std::logic_error("No more tokens");

        }

    }

}

std::shared_ptr<JSON::JSON_NODE> parseString(){

    std::cout<<"parsing string\n";

    std::shared_ptr<JSON::JSON_NODE> node =std::make_shared<JSON::JSON_NODE>();

    Token token=tokenizer.getToken();

    std::string *sValue=new std::string(token.value);

    node->setString(sValue);

    return node;


}

std::shared_ptr<JSON::JSON_NODE> parseNumber(){

    std::cout<<"Parsing number\n";

    std::shared_ptr<JSON::JSON_NODE> node=std::make_shared<JSON::JSON_NODE>();

    Token nextToken=tokenizer.gettoken();

    std::string value=nextToken.value;

    std::cout<<value<<"\n";

    float fvalue=std::stof(value);

    node->setFloat(fvalue);

    return node;

}

std::shared_ptr<JSON::JSON_NODE>parseBoolean(){

    std::cout<<"parsing boolean\n";

    std::shared_ptr<JSON::JSON_NODE> node=std::make_shared<JSON::JSON_NODE>();

    Token nextToken=tokenizer.getToken();

    node->setBool(nextToken.value=="True"?true:false);

    return node;

}

std::shared_ptr<JSON::JSON_NODE> parseNull(){

    std::cout<<"parsing Null\n";

    std::shared_ptr<JSON::JSON_NODE> node=std::make_shared<JSON::JSON_NODE>();

        node->setNull();

        return node;

}