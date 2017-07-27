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

    // Deleted copy constructor, defined move constructor
    Person(const Person& rhs) = delete;
    Person(Person&& rhs) = default;

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


