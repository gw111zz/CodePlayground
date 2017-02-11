#include <iostream>

struct MyObj {
    int x = 3;
};

int main() {
   {
        std::weak_ptr<MyObj> weakObj;

        std::shared_ptr<MyObj> strongObj = std::make_shared<MyObj>(); // Single allocation with make_shared

        weakObj = strongObj; // Strong count = 1; weak count = 1

        strongObj.reset(); // Strong count = 0; weak count = 1
    
        weakObj.reset(); // Strong count = 0; weak count = 0
    }

    {
        std::weak_ptr<MyObj> weakObj;

        std::shared_ptr<MyObj> strongObj = std::shared_ptr<MyObj>(new MyObj); // Two allocations (one for the object, one for the control block)

        weakObj = strongObj; // Strong count = 1; weak count = 1

        strongObj.reset(); // Strong count = 0; weak count = 1

        weakObj.reset(); // Strong count = 0; weak count = 0;
    }

    return 0;
}

/*

    KB
25.20^                                                                                                   #
     |                                                                                                   #
     |                                                                                                   #
     |                                                                                                   #
     |                                                                                      :::::::::::::#
     |                                                                                  @@:::            #
     |                                                                               :::@ : :            #
     |                                                                            :::: :@ : :            #
     |                                                                         :::: :: :@ : :            #
     |                                                                    :::::: :: :: :@ : :            #
     |                                                        ::::::::::::: :: : :: :: :@ : :            #
     |                                                    ::@@: :: :  ::: : :: : :: :: :@ : :            #
     |                                           :: ::::::: @ : :: :  ::: : :: : :: :: :@ : :            #
     |                                       ::::: :::: : : @ : :: :  ::: : :: : :: :: :@ : :            #
     |                             @@@    :@@:: :: :::: : : @ : :: :  ::: : :: : :: :: :@ : :            #
     |                             @  ::@@:@ :: :: :::: : : @ : :: :  ::: : :: : :: :: :@ : :            #
     |                      :::::::@  : @ :@ :: :: :::: : : @ : :: :  ::: : :: : :: :: :@ : :            #
     |             ::::::::::::    @  : @ :@ :: :: :::: : : @ : :: :  ::: : :: : :: :: :@ : :            #
     |            ::  :: :  :::    @  : @ :@ :: :: :::: : : @ : :: :  ::: : :: : :: :: :@ : :            #
     |            ::  :: :  :::    @  : @ :@ :: :: :::: : : @ : :: :  ::: : :: : :: :: :@ : :            #
   0 +--------------------------------------------------------------------------------------------------->KB
     0                                                                                               38.11

*/
