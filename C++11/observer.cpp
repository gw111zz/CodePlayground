#include <iostream>
#include <set>

/**
 * The Observer design pattern using smart pointers in C++11.
 */

class Observer {
public:
    virtual void onEvent() = 0;
};

class MyObserver : public Observer {
public:
    MyObserver() {
        std::cout << "MyObserver::MyObserver() constructor" << std::endl;
    }

    virtual ~MyObserver() {
        std::cout << "MyObserver::~MyObserver() destructor" << std::endl;
    }

    virtual void onEvent() override { 
        std::cout << "*** MyObserver::onEvent() ***" << std::endl;
    }
};

class Observed {
public:
    Observed() {
        std::cout << "Observed::Observed() constructor" << std::endl;
    }

    ~Observed() {
        std::cout << "Observed::~Observed() constructor" << std::endl;
        mObservers.clear();
    }

    void addObserver(std::shared_ptr<Observer> observer) {
        mObservers.insert(observer);
    }

    void removeObserver(std::shared_ptr<Observer> observer) {
        mObservers.erase(observer);
    }

    void triggerEvent() {
        for (auto iter = mObservers.begin(); iter != mObservers.end(); ++iter) {
            if (auto observer = (*iter).lock()) {
                observer->onEvent();
            } else {
                // N.B. Observers would have to take care of removing themselves from being a listener
                // otherwise expired weak_ptrs would accumulate in the mObservers list and the control
                // blocks of those would never be freed.
            }
        }
    }

private:
    // std::weak_ptr does not have a < operator so need to use the std::owner_less comparator
    std::set<std::weak_ptr<Observer>, std::owner_less<std::weak_ptr<Observer> > > mObservers;
};

int main() {

    std::unique_ptr<Observed> observedPtr(new Observed);

    std::shared_ptr<Observer> observer1Ptr(std::make_shared<MyObserver>());
    observedPtr->addObserver(observer1Ptr);

    std::cout << "One observer added" << std::endl;
    std::cout << "Trigger event..." << std::endl;
    observedPtr->triggerEvent();

    std::shared_ptr<Observer> observer2Ptr(std::make_shared<MyObserver>());
    observedPtr->addObserver(observer2Ptr);

    std::cout << "Another observer added" << std::endl;
    std::cout << "Trigger event..." << std::endl;
    observedPtr->triggerEvent();

    observedPtr->removeObserver(observer1Ptr);
    observedPtr->removeObserver(observer2Ptr);

    std::cout << "No observers added" << std::endl;
    std::cout << "Trigger event..." << std::endl;
    observedPtr->triggerEvent();

    return 0;
}
