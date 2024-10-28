#include <iostream>
#include <string>
/*class Cat { //первый вариант
    private:
    std::string name;
    public:
    Cat(const std::string& n) : name(n) {}
    const std::string& getName() const { return name; }
    std::string Voice() const {
        return "Meow";
    }
};
class Dog {
    private:
    std::string name;
    public:
    Dog(const std::string& n) : name(n) {}
    const std::string& getName() const { return name; }
    std::string Voice() const {
        return "Woof";
    }
};*/
/*enum class AnimalType { //второй вариант(лучше)
    Cat,
    Dog
};
class Animal {
   private:
    AnimalType type;
    std::string name;
    public:
    Animal(AnimalType t,const std::string& n) : type(t), name(n) {}
    const std::string& getName() const { return name; }
    std::string Voice() const {
        switch (type) {
            case AnimalType::Cat:
                return "Meow";
            case AnimalType::Dog:
                return "Woof";
            default:
                return "Unknown creature";
        }
    }
};

template <typename T>
void Process(const T& creature) {
    std::cout<<creature.GetName()<<"\n";
}
int main() {
   Animal c(AnimalType::Cat,"Tom");
    Animal d(AnimalType::Dog,"Sharik");
    return 0;
}*/

class Animal {
    protected:
    std::string name;
    public:
    Animal(const std::string& n) : name(n) {}
    const std::string& GetName() const {
        return name;
    }
   virtual std::string Voice() const {
        return "Generic Voice";
    }
};
class Cat : public Animal {
    public:
    Cat(const std::string& n) : Animal(n) {}
    std::string Voice() const override{
        return "Meow";
    }
};
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    std::string Voice() const override{
        return "Woof";
    }
};
class Shepherd:class Dog {
    public:
    Shepherd(const std::string& n) : Dog(n) {}
    std::string Voice() const override final {
        //
    }
};
void Process(const Animal& creature) {
    std::cout<<creature.Voice()<<"\n";
}
int main() {
    Cat c("Tom");
    Dog d("Sharik");
    Process(c);
    Process(d);
}