#include <iostream>
#include <vector>

struct MyObj {
    explicit MyObj(int v) : value(v) {}

    int value;
};

int main() {

    std::vector<MyObj> v;
    v.emplace_back(MyObj{1});
    v.emplace_back(MyObj{10});
    v.emplace_back(MyObj{100});

    std::cout << "Before remove_if" << std::endl;
    for (const auto& item : v)
    {
        std::cout << item.value << std::endl;
    }

    v.erase(std::remove_if(v.begin(), v.end(), [](MyObj& m) { return m.value == 10; }));

    std::cout << "After remove_if" << std::endl;
    for (const auto& item : v)
    {
        std::cout << item.value << std::endl;
    }

    return 0;
}
