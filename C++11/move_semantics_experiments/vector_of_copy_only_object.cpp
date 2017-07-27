#include <iostream>
#include <string>
#include <vector>

class Person
{
public:

    Person(std::string name, int age)
    : mName(std::move(name))
    , mAge(age)
    {}

    // Defined copy constructor, deleted move constructor
    Person(const Person& rhs) 
    {
        mName = rhs.mName;
        mAge = rhs.mAge;
    }
    //Person(Person&& rhs) = delete;

private:

    std::string mName;
    int mAge;
};

int main()
{
    std::vector<Person> personVector;
    for (int i = 0; i < 1000000000; ++i)
    {
        personVector.emplace_back(Person("Person", 20));
    }
    return 0;
}

