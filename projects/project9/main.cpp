#include <iostream>
struct WrongAgeException {
    int age;
};
int ReadAge() {
    std::cin.exceptions(std::iostream::failbit);
    int age;
    std::cin >> age;
    if(age<0||age>=128) {
        //return -1;
        throw WrongAgeException(age);
    }
    return age;
}
int main() {
    /* if(int age=ReadAge();age==-1) {
         std::cout<<"Wrong input!"<<std::endl;
     }else {
         std::cout<<age<<std::endl;
     }*/
    try {
        int age = ReadAge();
    }
    catch(const WrongAgeException& ex) {
        std::cerr<<"Age is not correct: "<<ex.age<<std::endl;
        return 1;
    }
    catch(const std::istream::failure& ex) {
        std::cerr<<"Failed to read istream: "<<ex.what()<<std::endl;
        return 1;
    }
    catch(...) {
        std::cerr<<"Unknown exception: "<<std::endl;
        return 1;
    }
}