#include <iostream>
#include <variant>
/*union student {
    int age;
    float averageScore;
    char* name;
};
int main() {
    student Samir;*/
   /* Samir.age = 15 ;
    std::cout <<"Samir age: "<< Samir.age << std::endl;
    Samir.averageScore = 2.5;
    std::cout <<"Samir score: "<<Samir.averageScore << "Samir age: "<< Samir.age << std::endl;;
    Samir.name = "Samir";
    std::cout <<"Samir name: "<< Samir.name << std::endl;*/
   /* std::cout << "Address 1: "<<&Samir.age<<std::endl;
    std::cout << "Address 2: "<<&Samir.averageScore<<std::endl;
    std::cout << "Address 3: "<<&Samir.name<<std::endl;
    std::cout <<"Size: "<<sizeof(Samir)<<std::endl;

}*/

int main() {
    std::variant<int, double> myExample;
    myExample = 11;
    myExample = 11.11;
    std::cout << std::get<double>(myExample) << std::endl;
}
