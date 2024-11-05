#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    Node* first = nullptr;
    Node* last = nullptr;
    int elementsCount = 0;

public:

    size_t Size() const {
        return elementsCount;
    }

    void PushBack(const T& elem) {
        ++elementsCount;

        Node* node = new Node(elem, last, nullptr);

        if (last != nullptr) {
            last->next = node;
        } else {
            first = node;
        }
        last = node;
    }
};

class C {
public:
    void f() noexcept{};
};

int main() {
    List<C> data;
    C element;

    try {
        data.PushBack(element);
    } catch (...) {
        std::cout << data.Size() << "\n";
    }
    return 0;
}