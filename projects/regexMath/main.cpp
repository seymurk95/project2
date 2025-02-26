#include <iostream>
#include <regex>
#include <string>
#include <cctype>

std::string removeSpaces(const std::string& input) {
  std::string output;

  for (char c : input) {
   if (!std::isspace(static_cast<unsigned char>(c))) {
    output.push_back(c);
   }
  }
 return output;
}

bool isValidMathExpression(const std::string& expr) {
 std::regex pattern(R"(^\s*[+\-]?\s*(?:(?:\d+(?:\.\d*)?)|(?:\.\d+))(?:\s*[\+\-\*\/\^]\s*[+\-]?\s*(?:(?:\d+(?:\.\d*)?)|(?:\.\d+)))*\s*$)");

 if (!std::regex_match(expr, pattern)) {
  return false;
 }

std::string s = removeSpaces(expr);

  size_t pos = 0;

 try {

 while (pos < s.size()) {

 char op = s[pos];

 pos++;
size_t numEnd = 0;
 double number = std::stod(s.substr(pos), &numEnd);

 pos += numEnd;

 if (op == '/' && number == 0.0) {
 return false;

 }

 }

 } catch (...) {
 return false;
}
 return true;

}


int main() {

 std::string expressions[] = {

  "-12 + - 7",  //c
"12. + 17", //c

 ".5 * 4",//c

 "12 / 0",  //i

 "12 / -0.0", // i

 "3 + 5 * - 2"  // c

 };



  for (const auto& expr : expressions) {

 std::cout << "expression: \"" << expr << "\" -> "
 << (isValidMathExpression(expr) ? "correcrt" : "incorrect") << std::endl;

 }

 return 0;

}