#include <iostream>
#include <set>

// Experiment to try out an ordered set

struct Obj {

    Obj(int insertIndex, int data) : mInsertIndex(insertIndex), mData(data) {}
    int mInsertIndex;
    int mData;
};

struct ObjCompare {
    bool operator()(const Obj& lhs, const Obj& rhs) const {
        return lhs.mInsertIndex > rhs.mInsertIndex;
    }
};

int main() {

    std::set<Obj, ObjCompare> mySet { {10, 2}, {20, 1}, {0, 3} };
    
    std::cout << "Set contains: " << std::endl;
    for (const auto& item : mySet) {
        std::cout << item.mData << std::endl;
    }

    return 0;
}

