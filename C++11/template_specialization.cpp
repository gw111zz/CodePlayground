#include <iostream>

template<typename T>
class A {
public:
    void foo(T t) { std::cout << t << std::endl; }
};

template<>
class A<int> {
public:
    void foo(int i) { std::cout << "An int " << i << std::endl; }
};

int main() {

    A<char> a;
    a.foo('c');

    A<int> b;
    b.foo(2);

    return 0;
}

