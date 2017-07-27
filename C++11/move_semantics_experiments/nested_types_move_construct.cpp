#include <iostream>
#include <string>

class Inner
{
public:
    Inner(std::string first, int second)
    : mFirst(std::move(first)), mSecond(second)
    {}

    // Default copy and move

private:
    const std::string mFirst;
    const int mSecond;
};

class Outer
{
public:
    Outer(Inner inner, std::string param)
    : mInner(std::move(inner)), mParam(std::move(param))
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
    // Where possible, initialization parameters are moved

    for (int i = 0; i < 1000000000; ++i)
    {
        Outer* outer = new Outer(Inner("first", i), "param");
        delete outer;
    }

};
