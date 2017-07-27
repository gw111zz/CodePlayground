#include <iostream>
#include <string>

class Inner
{
public:
    Inner(std::string first, int second)
    : mFirst(std::move(first)), mSecond(second)
    {
        std::cout << "Inner: user defined constructor" << std::endl;
    }

    ~Inner()
    {
        std::cout << "Inner: destructor" << std::endl;
    }

    Inner(const Inner& other)
    : mFirst(std::move(other.mFirst)), mSecond(other.mSecond)
    {
        std::cout << "Inner: copy constructor" << std::endl;
    }

    Inner(Inner&& other)
    : mFirst(std::move(other.mFirst)), mSecond(std::move(other.mSecond))
    {
        std::cout << "Inner: move constructor" << std::endl;
    }

    Inner& operator=(const Inner& other)
    {
        std::cout << "Inner: copy assignment" << std::endl;
        mFirst = other.mFirst;
        mSecond = other.mSecond;
        return *this;
    }

    Inner& operator=(Inner&& other)
    {
        std::cout << "Inner: move assignment" << std::endl;
        mFirst = std::move(other.mFirst);
        mSecond = std::move(other.mSecond);
        return *this;
    }

private:
    std::string mFirst;
    int mSecond;
};

class OuterInitByCopy
{
public:
    OuterInitByCopy(const Inner& inner)
    : mInner(inner)
    {
        std::cout << "OuterInitByCopy: user defined constructor" << std::endl;
    }

    ~OuterInitByCopy()
    {
        std::cout << "OuterInitByCopy: destructor" << std::endl;
    }

    OuterInitByCopy(const OuterInitByCopy& other)
    : mInner(other.mInner)
    {
        std::cout << "OuterInitByCopy: copy constructor" << std::endl;
    }

    OuterInitByCopy(OuterInitByCopy&& other)
    : mInner(other.mInner)
    {
        std::cout << "OuterInitByCopy: move constructor" << std::endl;
    }

    /*OuterInitByCopy& operator=(const OuterInitByCopy& other)
    {
        std::cout << "OuterInitByCopy: copy assignment" << std::endl;
        mInner = other.mInner;
    }

    OuterInitByCopy& operator=(OuterInitByCopy&& other)
    {
        std::cout << "OuterInitByCopy: move assignment" << std::endl;
        mInner = std::move(other.mInner);
    }*/


private:

    const Inner mInner;
};

class OuterInitByMove
{
public:
    OuterInitByMove(Inner inner)
    : mInner(std::move(inner))
    {
        std::cout << "OuterInitByMove: user defined constructor" << std::endl;
    }

    ~OuterInitByMove()
    {
        std::cout << "OuterInitByMove: destructor" << std::endl;
    }

    OuterInitByMove(const OuterInitByMove& other)
    : mInner(std::move(other.mInner))
    {
        std::cout << "OuterInitByMove: copy constructor" << std::endl;
    }

    OuterInitByMove(OuterInitByMove&& other)
    : mInner(std::move(other.mInner))
    {
        std::cout << "OuterInitByMove: move constructor" << std::endl;
    }

    /*OuterInitByMove& operator=(const OuterInitByMove& other)
    {
        std::cout << "OuterInitByMove: copy assignment" << std::endl;
        mInner = other.mInner;
    }

    OuterInitByMove& operator=(OuterInitByMove&& other)
    {
        std::cout << "OuterInitByMove: move assignment" << std::endl;
        mInner = std::move(other.mInner);
    }*/

private:

    const Inner mInner;
};

int main()
{
    std::cout << "****** Create an OuterInitByCopy *******" << std::endl;
    OuterInitByCopy initByCopy(Inner("param", 1));

    std::cout << std::endl;

    std::cout << "****** Create an OuterInitByMove *******" << std::endl;
    OuterInitByMove initByMove(Inner("param", 1));

    std::cout << std::endl;

    return 0;
}

