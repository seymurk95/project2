#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
cpp_int boost_factorial(int num) {
    cpp_int fact = 1;
    for (int i=num;i>1;--i)
        fact *= i;
    return fact;
}
int main() {
    int num = 32;
    std::cout << "Factorial of "<<num<<" is "<< boost_factorial(num);
    return 0;
}