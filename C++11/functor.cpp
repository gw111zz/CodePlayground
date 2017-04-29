#include <algorithm>
#include <iostream>

struct AddOneFunctor {
    int operator()(int x) {
        return x + 1;
    }
};

int main() {
    AddOneFunctor addOneFunctor;
    std::cout << "AddOneFunctor addOneFunctor(2) = " << addOneFunctor(2) << std::endl;
    return 0;
}

