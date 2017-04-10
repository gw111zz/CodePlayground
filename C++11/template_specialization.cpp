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

template<class T>
class A<T*> {
public:
    void foo(T* t) { std::cout << "Dereferenced " << *t << std::endl; }
};

template<>
void A<char*>::foo(char* c) { 
    std::cout << "Dereferenced char " << *c << std::endl; 
}

int main() {

    A<char> a;
    a.foo('c');

    A<int> b;
    b.foo(2);

    int i = 3;
    A<int*> c;
    c.foo(&i);

    char ch = 'd';
    A<char*> d;
    d.foo(&ch);

    return 0;
}

