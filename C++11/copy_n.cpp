#include <algorithm>
#include <iostream>
#include <vector>

int main() {

    std::vector<int> first { 1, 2, 3, 4, 5 };
    std::vector<int> second { 10, 20, 30, 40, 50 };
    std::copy_if(second.begin(), second.end(), std::back_inserter(first), [](int i) { return i % 20 == 0; });

    std::copy(first.begin(), first.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
