#include <iostream>
#include <memory>
#include <utility>

/*template<typename T> //четвёртая программа
class Forwardlist {
    private:
        struct Node {
            T data;
            std::unique_ptr<Node> next;
        };
    std::unique_ptr<Node> head;
    public:
        void Pushfront(const T& elem) {
            head = std::make_unique<Node>(elem,std::move(head));
        }
        void PopFront() {
            head = std::move(head->next);
        }
        const T& Front() const {
            return head->data;
        }
        bool Empty() const {
            return head == nullptr;
        }
        ~Forwardlist() {
            while (!Empty()) {
                PopFront();
            }
        }

};/*
/*int* f() {  вторая программа
    return new int(17);
}

std::unique_ptr<int> g() {
    return std::make_unique<int>(17);
}*/

/*void sendIn(std::unique_ptr<Logger>x) { //третья программа
    // можно вставить в проект логгер
}*/

int main() {
   /* int *ptr = new int(17); первая программа
    std::cout << *ptr << std::endl;
    delete ptr;
    std::unique_ptr<int> smart=std::make_unique<int>(17);
    std::cout << *smart << std::endl;
    return 0;*/


   /* std::cout << f() << std::endl; вторая программа
    std::cout << g() << std::endl;*/


    /* auto smart = std::make_unique<Logger>(); //третья программа
    sendIn(std::move(smart));
    // в проект с логгером*/

    std::shared_ptr<int> ptr1=std::make_shared<int>(17); //пятая программа
    std::cout<<*ptr1<<std::endl;
    std::cout<<ptr1.use_count()<<std::endl;
    auto ptr2=ptr1;
    std::cout<<ptr1.use_count()<<std::endl;
    std::cout<<ptr2.use_count()<<std::endl;
    std::shared_ptr<int> ptr3;
    std::cout<<ptr3.use_count()<<std::endl;
    ptr3=ptr1;
    std::cout<<*ptr3<<std::endl;
    std::cout<<ptr3.use_count()<<std::endl;


    return 0;

}
