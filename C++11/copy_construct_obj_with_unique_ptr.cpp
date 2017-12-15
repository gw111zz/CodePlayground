#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Node {
public:

    Node(std::string name) : mName(name) {}
    ~Node() = default;

    Node& operator=(Node&&) = delete;
    Node(Node&&) = delete;

    Node(Node& other) {
        mName = other.mName;
        std::cout << "Copy construct " << mName << std::endl;
        for (const std::unique_ptr<Node>& child : other.mChildren) {
            std::unique_ptr<Node> newChild = std::make_unique<Node>(*child.get());
            std::cout << "Create child " << newChild->mName << std::endl;
            AddChild(std::move(newChild));
        }
    }

    Node& operator=(Node&) = delete;

    const std::string& GetName() const {
        return mName;
    }

    void AddChild(std::unique_ptr<Node> child) {
        mChildren.emplace_back(std::move(child));
    }

    std::vector<std::unique_ptr<Node>>& GetChildren() {
        return mChildren;
    }

private:

    std::string mName;
    std::vector<std::unique_ptr<Node>> mChildren;
};

int main() {

    Node root("Root");
    
    auto childAPtr = std::make_unique<Node>("Child A");
    root.AddChild(std::move(childAPtr));
    auto childBPtr = std::make_unique<Node>("Child B");
    root.AddChild(std::move(childBPtr));
    auto childCPtr = std::make_unique<Node>("Child C");
    root.AddChild(std::move(childCPtr));
    
    auto childAAPtr = std::make_unique<Node>("Child AA");
    root.GetChildren().at(0)->AddChild(std::move(childAAPtr));

    std::cout << "Make copy" << std::endl;
    Node rootCopy(root);
    std::cout << "Finished making copy" << std::endl;
    std::cout << "Child of the first child of the root = " << rootCopy.GetChildren().at(0)->GetChildren().at(0)->GetName() << std::endl; // Shuold be Child AA

    return 0;
}

