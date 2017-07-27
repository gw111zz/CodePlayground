#include <iostream>
#include <string>

class Inner
{
public:
    Inner(const std::string& first, int second)
    : mFirst(first), mSecond(second)
    {}

    // Default copy and move

private:
    const std::string mFirst;
    const int mSecond;
};

class Outer
{
public:
    Outer(const Inner& inner, std::string param)
    : mInner(inner), mParam(std::move(param))
    {}

    // Default copy and move

private:
    const Inner mInner;
    const std::string mParam;
};

int main()
{
    // There is a class Outer which owns an Inner
    // Both have default copy and move constructors
    // User defined types which are initialization parameters are passed in by const reference
    // and then copied to a member

    for (int i = 0; i < 1000000000; ++i)
    {
        Outer* outer = new Outer(Inner("first", i), "param");
        delete outer;
    }

};

