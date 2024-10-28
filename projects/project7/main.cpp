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
class C {
    private:
    A a;
    int y;
    public:
    void Func1() {
        return a.Func1();
    }
    void Func2() {};
    void Func3() {};
    const A& GetA() const {
        return a;
    }
};
int main() {
   /* B b;
    b.Func1();
    b.Func2();
    b.A::Func2();
    b.Func3();
    std::cout<<sizeof(A)<<" "<<sizeof(B)<<"\n";*/
    C  c;
    c.Func1();
    c.Func2();
    c.Func3();
    DoSomething(c.GetA());
}
