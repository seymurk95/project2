#include <iostream>
class C {
    public:
    int x=0;
    inline static int sx=0;
    static const int scx=100;
};
int main()
{
    std::cout << C::sx <<" "<< C::scx <<"\n";;

    C::sx=1;
    std::cout<<C::sx<<" "<<C::scx<<"\n";
    C c1,c2;
    c1.x=42;
    c2.x=17;
    c2.sx=13;
    std::cout<<C::sx<<" "<<C::scx<<"\n";
    std::cout<<c1.x<<" "<<c1.scx<<"\n";
    std::cout<<c2.x<<" "<<c2.scx<<"\n";
    return 0;
}
