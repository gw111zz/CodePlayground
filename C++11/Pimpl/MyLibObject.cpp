#include <iostream>
#include <string>
#include <vector>

#include "MyLibObject.h"

struct MyLibObject::Impl {
    // Internal members here
    // Can add more without changing the header file which clients use
    std::string mName;
    std::vector<int> mData;
};

namespace std 
{
    template<typename T, typename... Ts>
    std::unique_ptr<T> make_unique(Ts&&... params) 
    {
        return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
    }
}

MyLibObject::MyLibObject() : mImpl(std::make_unique<Impl>())
{}

MyLibObject::~MyLibObject() = default;

MyLibObject::MyLibObject(MyLibObject&& rhs) noexcept = default;

MyLibObject& MyLibObject::operator=(MyLibObject&& rhs) noexcept = default;

MyLibObject::MyLibObject(const MyLibObject& rhs) : mImpl(nullptr)
{
    if (rhs.mImpl) {
        mImpl = std::make_unique<Impl>(*rhs.mImpl);
    }
}

MyLibObject& MyLibObject::operator=(const MyLibObject& rhs)
{
  if (!rhs.mImpl) {
      mImpl.reset();
  } else if (!mImpl) {
      mImpl = std::make_unique<Impl>(*rhs.mImpl);
  } else {
      *mImpl = *rhs.mImpl;
  }

  return *this;
}

void MyLibObject::doSomething() 
{
    std::cout << "MyLibObject::doSomething()" << std::endl;
}

