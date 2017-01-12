#include <iostream>
#include <memory>

class Foo;
void doPrintFoo(std::shared_ptr<Foo> pFoo);

/**
 * enable_shared_from_this requires an object to be owned by a shared_ptr.
 * To force clients of Foo to always have Foo in a shared_ptr, make the
 * constructor private and create a public static factory function that
 * they need to use.
 */
class Foo : public std::enable_shared_from_this<Foo> {

public:
    
    static std::shared_ptr<Foo> create() {
        std::cout << "Foo::create() static creation function" << std::endl;
        return std::shared_ptr<Foo>(new Foo());
    }

    ~Foo() { std::cout << "Foo::~Foo() destructor" << std::endl; }

    /**
     * A function that requires passing a shared_ptr of this to another function.
     */
    void printFoo() { doPrintFoo(shared_from_this()); }

private:
    Foo() { std::cout << "Foo::Foo() default constructor" << std::endl; }
};

void doPrintFoo(std::shared_ptr<Foo> pFoo) {
    std::cout << "Foo refCount = " << pFoo.use_count() << std::endl;
}

int main() {

    std::shared_ptr<Foo> foo = Foo::create();
    foo->printFoo();

    return 0;
}
