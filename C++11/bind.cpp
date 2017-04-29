#include <functional>
#include <iostream>

long add(int x, int y) { 
    return x + y;
}

struct Adder {
    long add(int x, int y) {
        return x + y;
    }
};

int main() {
    auto addOne = std::bind(add, std::placeholders::_1, 1);
    std::cout << "addOne(2) = " << addOne(2) << std::endl;

    Adder adder;
    auto addOneFromAdder = std::bind(&Adder::add, &adder, std::placeholders::_1, 1);
    std::cout << "addOneFromAdder(2) = " << addOneFromAdder(2) << std::endl;
    return 0;
}
