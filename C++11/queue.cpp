#include <algorithm>
#include <iostream>
#include <deque>

struct Obj {

    explicit Obj(int data) : mData(data) {}
    int mData;

    bool operator==(const Obj& other) const {
        return mData == other.mData;
    }
};

int main() {

    std::deque<Obj> q;
    q.push_back(Obj(1));
    q.push_back(Obj(2));
    q.push_back(Obj(3));

    for (const auto& item : q) {
        std::cout << item.mData << std::endl;
    }

    bool found = std::find(q.begin(), q.end(), Obj(2)) != q.end();
    if (found) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}
