#include <iostream>
#include <regex>
#include <string>
int main() {
    /*std::string s{"love MSU Baku"};
    std::regex r{"MSU[a-z,A-Z, ]+"};*/
    std::string s{"love MSU Baku"};
    std::regex r{"MSU[a-z,A-Z, ]?"};

    /*if (std::regex_match(s, r)) {
        std::cout <<"String matches regex"<< std::endl;
    }
    if (std::regex_match(s.begin(), s.end(), r)) {
        std::cout <<"Substring matches regex"<< std::endl;
    }*/

    /*std::smatch result;
    std::regex_search(s,result,r);
    for(auto x:result) {
        std::cout << x << " ";
    }*/

    std::cout<<std::regex_replace(s,r,"Lomonosov uneversity ");
    return 0;
}
