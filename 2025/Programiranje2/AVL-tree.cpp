#include "constants.h"

#ifdef AVL_TREE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

struct Node
{
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int value) : key(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
protected:
    Node *root = nullptr;

    int height(Node *node) const
    {
        return node 
            ? node->height 
            : 0;
    }

    int balanceFactor(Node *node) const
    {
        return node 
            ? height(node->left) - height(node->right) 
            : 0;
    }

    void updateHeight(Node *node)
    {
        if (node)
            node->height = 1 + std::max(height(node->left), height(node->right));
    }

    Node *rotateRight(Node *node)
    {
        Node *leftSubNode = node->left;
        Node *rightSubSubNode = leftSubNode->right;

        leftSubNode->right = node;
        node->left = rightSubSubNode;

        updateHeight(node);
        updateHeight(leftSubNode);

        return leftSubNode;
    }

    Node *rotateLeft(Node *node)
    {
        Node *rightSubNode = node->right;
        Node *leftSubSubNode = rightSubNode->left;

        rightSubNode->left = node;
        node->right = leftSubSubNode;

        updateHeight(node);
        updateHeight(rightSubNode);

        return rightSubNode;
    }

    Node *rebalance(Node *node)
    {
        updateHeight(node);

        int balance = balanceFactor(node);

        // levo je pretežko
        if (balance > 1)
        {
            if (balanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left); // LR zasuk
            return rotateRight(node); // LL zasuk
        }

        // desno je pretežko
        if (balance < -1)
        {
            if (balanceFactor(node->right) > 0)
                node->right = rotateRight(node->right); // RL zasuk
            return rotateLeft(node); // RR zasuk
        }

        return node;
    }

    Node *insert(Node *node, int key)
    {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // podvojene ključe ignoriram

        return rebalance(node);
    }

    Node *findMin(Node *node) const
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node *remove(Node *node, int key)
    {
        if (!node)
            return nullptr;

        if (key < node->key)
            node->left = remove(node->left, key);
        else if (key > node->key)
            node->right = remove(node->right, key);
        else
        {
            // brez otrok ali z enim otrokom
            if (!node->left || !node->right)
            {
                Node *child = node->left ? node->left : node->right;
                delete node;
                return child;
            }

            // z dvema otrokoma:
            // zamenjam z najmanjšim elementom desnega poddrevesa
            Node *minNode = findMin(node->right);
            node->key = minNode->key;
            node->right = remove(node->right, minNode->key);
        }

        return rebalance(node);
    }

    void destroy(Node *node)
    {
        if (!node)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    ~AVLTree()
    {
        destroy(root);
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    void remove(int key)
    {
        root = remove(root, key);
    }
};

class AVLTreeConsole : public AVLTree
{
private:
    void preorder(Node* node) const
    {
        if (!node)
            return;

        std::cout << node->key << ' ';
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node) const
    {
        if (!node)
            return;

        inorder(node->left);
        std::cout << node->key << ' ';
        inorder(node->right);
    }

    void postorder(Node* node) const
    {
        if (!node)
            return;

        postorder(node->left);
        postorder(node->right);
        std::cout << node->key << ' ';
    }

    int treeHeight(Node* node) const
    {
        if (!node) return 0;
        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }

    void printOut(Node* root) const
    {
        if (!root)
        {
            std::cout << "(empty)\n";
            return;
        }

        int h = treeHeight(root);
        std::queue<Node*> q;
        q.push(root);

        for (int level = 1; level <= h; ++level)
        {
            int count = q.size();

            int indent = (1 << (h - level)) - 1;
            int between = (1 << (h - level + 1)) - 1;

            for (int i = 0; i < indent; ++i)
                std::cout << "    ";

            for (int i = 0; i < count; ++i)
            {
                Node* node = q.front();
                q.pop();

                if (node)
                {
                    std::cout << std::setw(4) << node->key;
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    std::cout << std::setw(4) << "___";
                    q.push(nullptr);
                    q.push(nullptr);
                }

                for (int j = 0; j < between; ++j)
                    std::cout << "    ";
            }

            std::cout << '\n';
        }
    }

public:
    void printPreOrder() const
    {
        preorder(root);
        std::cout << '\n';
    }

    void printInOrder() const
    {
        inorder(root);
        std::cout << '\n';
    }

    void printPostOrder() const
    {
        postorder(root);
        std::cout << '\n';
    }

    void printTree() const
    {
        printOut(root);
        std::cout << '\n';
    }
};

int main()
{
    AVLTreeConsole tree;

    std::vector<int> addNumbers = { 10, 3, 7, 8, 9, 12, 18, 26, 22, 6, 4 };
    for (std::vector<int>::iterator v = addNumbers.begin(); v != addNumbers.end(); ++v)
    {
        std::cout << "Dodaj: " << *v << "\n\n";
        tree.insert(*v);
        // tree.printTree();
    }

    std::cout << "Result ";
    tree.printTree();

    tree.printPreOrder();
    tree.printInOrder();
    tree.printPostOrder();

    std::vector<int> removeNumbers = { 3, 7, 8, 9, 4 };
    for (std::vector<int>::iterator v = removeNumbers.begin(); v != removeNumbers.end(); ++v)
    {
        std::cout << "Odstrani: " << *v << "\n\n";
        tree.remove(*v);
        // tree.printTree();
    }
    
    return 0;
}
#endif