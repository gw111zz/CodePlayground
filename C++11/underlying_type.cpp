#include <iostream>
#include <limits>

using MyEnumUnderlyingType = uint32_t;
constexpr MyEnumUnderlyingType kMaxValue = std::numeric_limits<MyEnumUnderlyingType>::max();

enum class MyEnum : MyEnumUnderlyingType {
    Apples  = 0, 
    Pears   = 1,
    Oranges = 2,
    Max = kMaxValue
};

int main() {

    std::cout << "uint32_t limit: " << std::numeric_limits<std::underlying_type<MyEnum>::type>::max() << std::endl;
    std::cout << "MyEnum::Max: " << static_cast<MyEnumUnderlyingType>(MyEnum::Max);

    return 0;
}
