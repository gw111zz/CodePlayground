#include <bitset>
#include <iostream>

int main() {
    constexpr int kFirst     = 0x01 << 0;
    constexpr int kSecond    = 0x01 << 1;
    constexpr int kThird     = 0x01 << 2;

    std::bitset<3> types(0);
    types |= kFirst;
    std::cout << "types |= kFirst = " << std::hex << types << std::endl;

    std::bitset<3> types2(kSecond | kThird);
    std::cout << "kSecond | kThird = " << types2 << std::endl;

    std::cout << "All set? " << types2.all() << std::endl;

    std::bitset<3> types3(kFirst | kSecond | kThird);
    std::cout << "kFirst | kSecond | kThird = " << types3 << std::endl;

    std::cout << "All set? " << types3.all() << std::endl;

    return 0;
}
