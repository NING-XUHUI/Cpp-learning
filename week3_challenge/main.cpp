/**
 实现一个函数，该函数计算二叉树中每个节点的高度并将其存储在树的每个节点中。回想一下，节点的高度是其最长的子节点链的边数。

假设一棵树的根节点a有两个子节点B1和B2。假设节点B1没有子节点。假设节点B2有一个子节点C，那么A的高度就是2，因为它最长的子链(A -> B2 -> C)有两条边(A -> B2和B2 -> C)。

下面的启动代码定义了一个名为“Node”的类，它有两个子指针(“left”、“right”)和一个整数“height”成员变量。还有一个构造函数节点()将子节点初始化为nullptr，将高度初始化为-1。

您的工作是实现“computeHeight(Node *n)”过程，该过程计算节点n的高度及其子节点(如果有的话)的高度。

还有一个辅助函数“printTree(const节点*n)”，它打印当前高度，以内嵌括号的形式显示树。如果一个子元素是nullptr，那么它将以一对空括号的形式出现:“()”。构造函数初始化高度为-1，即使没有子节点的高度应该为0。如果在运行computeHeight()过程后看到任何-1项，则可能会错过一个或多个节点。

您也可以使用帮助函数printTreeVertical(const Node *n)(尽管没有显示其复杂的定义)。它将显示树的详细的垂直打印输出，其中根显示在顶部，左子节点显示在比右子节点更高的行上。
 */
/*
The height of a node is the number of edges in
its longest chain of descendants.

Implement computeHeight to compute the height
of the subtree rooted at the node n. Note that
this function does not return a value. You should
store the calculated height in that node's own
height member variable. Your function should also
do the same for EVERY node in the subtree rooted
at the current node. (This naturally lends itself
to a recursive solution!)

Assume that the following includes have already been
provided. You should not need any other includes
than these.



You have also the following class Node already defined.
You cannot change this class definition, so it is
shown here in a comment for your reference only:


*/


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class Node {
public:
    int height; // to be set by computeHeight()
    Node *left, *right;
    Node() { height = -1; left = right = nullptr; }
    ~Node() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }
};

int getHeight(Node *n){
    if (nullptr == n){
        return 0;
    }

    int leftHeight = getHeight(n->right);
    int rightHeight = getHeight(n->left);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

}


void computeHeight(Node *n) {

    if (n){
        n->height = getHeight(n) - 1;
    }
    if (n->left){
        computeHeight(n->left);
    }
    if (n->right){
        computeHeight(n->right);
    }

}

// This function prints the tree in a nested linear format.
void printTree(const Node *n) {
    if (!n) return;
    std::cout << n->height << "(";
    printTree(n->left);
    std::cout << ")(";
    printTree(n->right);
    std::cout << ")";
}

// The printTreeVertical function gives you a verbose,
// vertical printout of the tree, where the leftmost nodes
// are displayed highest. This function has already been
// defined in some hidden code.
// It has this function prototype: void printTreeVertical(const Node* n);

// This main() function is for your personal testing with
// the Run button. When you're ready, click Submit to have
// your work tested and graded.
int main() {
    Node *n = new Node();
    n->left = new Node();
    n->right = new Node();
    n->right->left = new Node();
    n->right->right = new Node();
    n->right->right->right = new Node();

    computeHeight(n);

    printTree(n);
    std::cout << std::endl << std::endl;
//    printTreeVertical(n);

    // The Node destructor will recursively
    // delete its children nodes.
    delete n;
    n = nullptr;

    return 0;
}

