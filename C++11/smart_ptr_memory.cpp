#include <iostream>

struct MyObj {
    int x[100000];
};

/**
 * Compile with: g++ -g -std=c++11 smart_ptr_memory.cpp -o smart_ptr_memory
 * Run Valgrind with: valgrind --tool=massif --time-unit=B  ./smart_ptr_memory
 * Read the massive output with: ms_print <massif file generated by previous step> | less 
 *
 *     KB
 * 415.7^                                                      :::::::::::::::::
 *      |                   #################                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      |                   #                                  :
 *      | @:::::::::::::::::#                :::::::::::::::::::                :
 *    0 +----------------------------------------------------------------------->MB
 *      0                                                                   1.563
 * 
 * Number of snapshots: 60
 * Detailed snapshots: [14, 16, 18, 30, 37, 38, 47, 51, 54 (peak)]
 *
 */
int main() {

    // Create a large object with std::make_shared and make a weak_ptr point to it.
    // A single allocation for the object and the smart pointer control block is made.
    // The shared_ptr is then reset so there are no more shared references to it.
    // When the weak_ptr goes out of scope, the whole block of memory is freed.
    // So it should be possible to see memory go down to almost zero 
    // when the second large object is created at the end of this file.
    {
        std::weak_ptr<MyObj> weakObj;

        std::shared_ptr<MyObj> strongObj = std::make_shared<MyObj>(); // Single allocation with make_shared

        weakObj = strongObj; // Strong count = 1; weak count = 1

        strongObj.reset(); // Strong count = 0; weak count = 1
    }
    // Strong count = 0; weak count = 0; memory freed

    std::shared_ptr<MyObj> strongObj2 = std::make_shared<MyObj>(); // Another single allocation with make_shared

    return 0;
}

