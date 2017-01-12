#ifndef MY_LIB_OBJECT
#define MY_LIB_OBJECT

#include <memory>

class MyLibObject {

public:

    MyLibObject();
    ~MyLibObject();

    MyLibObject(MyLibObject&& rhs) noexcept;
    MyLibObject& operator=(MyLibObject&& rhs) noexcept;

    MyLibObject(const MyLibObject& rhs);
    MyLibObject& operator=(const MyLibObject& rhs);

    void doSomething();

private:

    struct Impl;
    std::unique_ptr<Impl> mImpl;

};

#endif // MY_LIB_OBJECT
