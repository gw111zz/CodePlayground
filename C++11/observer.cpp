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

    void addObserver(std::weak_ptr<Observer> observer) {
        mObservers.insert(observer);
    }

    void removeObserver(std::weak_ptr<Observer> observer) {
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
    std::set<std::weak_ptr<Observer>, std::owner_less<std::weak_ptr<Observer> > > mObservers;
};

int main() {

    std::unique_ptr<Observed> observedPtr(new Observed);

    std::shared_ptr<Observer> observer1Ptr(std::make_shared<MyObserver>());
    std::weak_ptr<Observer> observer1WeakPtr(observer1Ptr);
    observedPtr->addObserver(observer1WeakPtr);

    std::cout << "One observer added" << std::endl;
    std::cout << "Trigger event..." << std::endl;
    observedPtr->triggerEvent();

    std::shared_ptr<Observer> observer2Ptr(std::make_shared<MyObserver>());
    std::weak_ptr<Observer> observer2WeakPtr(observer2Ptr);
    observedPtr->addObserver(observer2WeakPtr);

    std::cout << "Another observer added" << std::endl;
    std::cout << "Trigger event..." << std::endl;
    observedPtr->triggerEvent();

    observedPtr->removeObserver(observer1WeakPtr);
    observedPtr->removeObserver(observer2WeakPtr);

    std::cout << "Remove all observers" << std::endl;
    std::cout << "Trigger event..." << std::endl;
    observedPtr->triggerEvent();

    return 0;
}
