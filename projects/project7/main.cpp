#include <iostream>
class A {
    private:
    int x;
    public:
    void Func1(){};
    void Func2(){};
};
class B: public A {
    private:
    int y;
    public:
    void Func2(){};
    void Func3(){};
};
int main() {
    B b;
    b.Func1();
    b.Func2();
    b.A::Func2();
    b.Func3();
    std::cout<<sizeof(A)<<" "<<sizeof(B)<<"\n";
}
