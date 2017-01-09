#include <iostream>

class Foo {

public:
    Foo() { std::cout << "Foo::Foo() constructor" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo() destructor" << std::endl; }

    void Log() { std::cout << "Foo::Log()" << std::endl; }
};

int main() {


    auto deleteFoo = [](Foo* pFoo) {
                        pFoo->Log();
                        delete pFoo;
                     };

    /*
     * Using unique_ptr with a custom deleter.
     */
    {
        std::cout << std::endl << "unique_ptr:" << std::endl;

        // Create unique_ptr with custom deleter
        std::unique_ptr<Foo, decltype(deleteFoo)> pFoo(new Foo(), deleteFoo);
    }

    /*
     * Using shared_ptr with a custom deleter.
     */
    {
        std::cout << std::endl << "shared_ptr:" << std::endl;

        // Create shared_ptr with custom deleter
        // N.B. make_shared cannot be used with a custom deleter 
        std::shared_ptr<Foo> pFoo(new Foo(), deleteFoo);
    }

    return 0;
}

