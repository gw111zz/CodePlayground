#include <iostream>
#include <vector>

class MyObject
{
public:
    explicit MyObject(std::string name)
    : mName(std::move(name))
    {
        std::cout << "MyObject: user defined constructor" << std::endl;
    }

    ~MyObject()
    {
        std::cout << "MyObject: destructor" << std::endl;
    }

    MyObject(const MyObject& other)
    : mName(std::move(other.mName))
    {
        std::cout << "MyObject: copy constructor" << std::endl;
    }

    MyObject(MyObject&& other)
    : mName(std::move(other.mName))
    {
        std::cout << "MyObject: move constructor" << std::endl;
    }

    MyObject& operator=(const MyObject& other)
    {
        std::cout << "MyObject: copy assignment" << std::endl;
        mName = other.mName;
        return *this;
    }

    MyObject& operator=(MyObject&& other)
    {
        std::cout << "MyObject: move assignment" << std::endl;
        mName = std::move(other.mName);
        return *this;
    }

    const std::string& getName() const
    {
        return mName;
    }

private:
    std::string mName;
};

class MyObject2
{
public:
    explicit MyObject2(std::string name)
    : mName(std::move(name))
    {
        std::cout << "MyObject2: user defined constructor" << std::endl;
    }

    ~MyObject2()
    {
        std::cout << "MyObject2: destructor" << std::endl;
    }

    MyObject2(const MyObject2& other)
    : mName(std::move(other.mName))
    {
        std::cout << "MyObject2: copy constructor" << std::endl;
    }

    MyObject2(MyObject2&& other)
    : mName(std::move(other.mName))
    {
        std::cout << "MyObject2: move constructor" << std::endl;
    }

    MyObject2& operator=(const MyObject2& other)
    {
        std::cout << "MyObject2: copy assignment" << std::endl;
        mName = other.mName;
        return *this;
    }

    MyObject2& operator=(MyObject2&& other)
    {
        std::cout << "MyObject2: move assignment" << std::endl;
        mName = std::move(other.mName);
        return *this;
    }

    const std::string& getName() const
    {
        return mName;
    }

private:
    std::string mName;
};

struct ToMyObject2 : public std::unary_function<MyObject2, MyObject>
{
    MyObject2 operator()(const MyObject& obj) const
    {
        return MyObject2(obj.getName());
    }
};

int main()
{
    // Transform std::vector of MyObjects to a std::vector of MyObject2s
    std::vector<MyObject> objs;
    objs.emplace_back(MyObject("One"));
    objs.emplace_back(MyObject("Two"));
    objs.emplace_back(MyObject("Three"));
    std::vector<MyObject2> obj2s;
    
    std::cout << "Transform with std::transform..." << std::endl;
    std::transform(objs.begin(), objs.end(), std::back_inserter(obj2s), ToMyObject2());
    std::cout << "objs.size(): " << objs.size() << ", obj2s.size(): " << obj2s.size() << std::endl;

    std::cout << "Transform with a loop..." << std::endl;
    std::vector<MyObject2> obj2s2;
    for (const auto& obj : objs)
    {
        obj2s2.emplace_back(MyObject2(obj.getName()));
    }
    std::cout << "objs.size(): " << objs.size() << ", obj2s2.size(): " << obj2s2.size() << std::endl;

    return 0;
}
