#include <iostream>
#include<string>
class Shape {
    protected:
    std::string name;
    public:
    Shape(const std::string& n) : name(n) {}
    const std::string& getName() const {
        return name;
    }
   virtual std::string Angles() const {}
   virtual std::string Spaces() const {}
};
class Ellipse : public Shape {
    public:
    Ellipse(const std::string& n) : Shape(n) {}
    std::string Angles() const override {
        return "0";
    }
    std::string Spaces() const override {
        return "pi*a*b";
    }

};
class Quadrangle : public Shape {
    public:
    Quadrangle(const std::string& n) : Shape(n) {}
    std::string Angles() const override{
        return "4";
    }
    std::string Spaces() const override {
        return "a*b";
    }
};
class Circle : public Ellipse {
    public:
    Circle(const std::string& n) : Ellipse(n) {}
    std::string Angles() const override final {
        return "0";
    }
    std::string Spaces() const override {
        return "pi*r^2";
    }
};
class Rectangle : public Quadrangle {
    public:
    Rectangle(const std::string& n) : Quadrangle(n) {}
    std::string Angles() const override {
        return "4";
    }
    std::string Spaces() const override {
        return "a*b";
    }
};
class Square : public Rectangle {
    public:
    Square(const std::string& n) : Rectangle(n) {}
    std::string Angles() const override final {
        return "4";
    }
    std::string Spaces() const override {
        return "a*a or a^2";
    }
};
void Process(const Shape& shape) {
    std::cout << shape.Angles() << std::endl;
}
int main() {
    Square s("square");
    Ellipse e("ellipse");
    Process(s);
    Process(e);
}
