#include <iostream>
#include <sstream>
#include <string>

class Person {

public:
    Person(std::string name, int age) : mName(std::move(name)), mAge(age) {
    }

    friend std::ostream& operator<<(std::ostream& stream, const Person& person) {
        return stream << "Person(name:" << person.mName << ", age:" << person.mAge << ")";
    }

private:

    std::string mName;
    int mAge;
};

int main() {

    Person p("Bob", 10);
    std::cout << "Printing person: " << p << std::endl;
    return 0;
}
