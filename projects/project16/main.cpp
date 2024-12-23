#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
int128_t boost_product(long long A,long long B) {
    int128_t ans = (int128_t)A*B;
    return ans;
}
int main() {
    long long first = 8437874535734867545;
    long long second = 2332445547646;
    std::cout<<"product of "<<first<<" and "<<second<<" is "<<boost_product(first,second);
}
