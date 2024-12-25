#include<boost/circular_buffer.hpp>
#include<boost/multiprecision/cpp_int.hpp>
using boost::circular_buffer;
template<typename T>
void print_buffer(circular_buffer<T> cbuf) {
    for(const auto& item : cbuf ) {
        std::cout << item << "; ";

    }
    std::cout << std::endl;
}

int main() {
    circular_buffer<int> cb(10);
    for(int i = 0; i != 10; i++) {
        cb.push_back(i);
    }
    print_buffer(cb);
    std::cout<<"cb.back: "<<cb.back()<<std::endl;
    std::cout<<"cb.front: "<<cb.front()<<std::endl;
    for(int i = 0; i != 5; i++) {
        cb.push_front(i);
    }
    print_buffer(cb);
    std::cout<<"cb.back: "<<cb.back()<<std::endl;
    std::cout<<"cb.front: "<<cb.front()<<std::endl;
    cb.pop_back();
    print_buffer(cb);
    cb.pop_front();
    print_buffer(cb);

}