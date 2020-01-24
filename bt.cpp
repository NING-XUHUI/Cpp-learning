#include <iostream>

class Node {
public:
  Node *left, *right;
  Node() { left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};



int count(Node *n) {

    int n1,n2;

    if (n == nullptr){
        return  0;
    } else
    {
        n1 = count(n->left);
        n2 = count(n->right);

        return n1 + n2 + 1;
    }


}

int main() {
    Node *n = new Node();
    n->left = new Node();
    n->right = new Node();
    n->right->left = new Node();
    n->right->right = new Node();
    n->right->right->right = new Node();

    // This should print a count of six nodes
    std::cout << count(n) << std::endl;

    // Deleting n is sufficient to delete the entire tree
    // because this will trigger the recursively-defined
    // destructor of the Node class.
    delete n;
    n = nullptr;

    return 0;
}