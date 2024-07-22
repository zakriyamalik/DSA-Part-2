//#include <iostream>
//using namespace std;
//class Node {
//public:
//    int data;
//    Node* left;
//    Node* right;
//    Node(int val)
//    {
//        data = val;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//class BST {
//public:
//    Node* root;
//    BST()
//    {
//        root = nullptr;
//    }
//    int max(int a, int b)
//    {
//        if (a > b) {
//            return a;
//        }
//        else {
//            return b;
//        }
//    }
//
//    int height_check(Node* node) 
//    { 
//        if (node == nullptr)
//        {
//            return 0;
//        }
//
//        int l = height_check(node->left);
//        int r = height_check(node->right);
//
//        if (l > r) {
//            return l + 1;
//        }
//        else {
//            return r + 1;
//        }
//    }
//
//    int balancefnction(Node* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//
//        int l = height_check(node->left);
//        int r = height_check(node->right);
//
//        return l - r;
//    }
//    void rotateLeft(Node*& node)
//    {
//        Node* newnode = node->right;
//        node->right = newnode->left;
//        newnode->left = node;
//        node = newnode;
//    }
//    void rotateRight(Node*& node)
//    {
//        Node* newnode = node->left;
//        node->left = newnode->right;
//        newnode->right = node;
//        node = newnode;
//    }
//    bool insert(Node*& node, int val)
//    {
//        if (node == nullptr) {
//            node = new Node(val);
//            return true;
//        }
//
//        if (val < node->data)
//        {
//            if (insert(node->left, val))
//            {
//                balancefnction(node);
//                return true;
//            }
//        }
//        else if (val > node->data)
//        {
//            if (insert(node->right, val))
//            {
//                balancefnction(node);
//                return true;
//            }
//        }
//        else
//        {
//            return false;
//        }
//
//        return false;
//    }
//    void inorder(Node* node)
//    {
//        if (node)
//        {
//            inorder(node->left);
//            cout << node->data << " ";
//            inorder(node->right);
//        }
//    }
//
//    Node* search(Node* node, int key)
//    {
//        while (node != nullptr && node->data != key)
//        {
//            if (key < node->data) {
//                node = node->left;
//            }
//            else
//            {
//                node = node->right;
//            }
//        }
//
//        return node;
//    }
//    void delete_function(Node* node) {
//        if (node) {
//            delete_function(node->left);
//            delete_function(node->right);
//            delete node;
//        }
//    }
//    void insert(int value)
//    {
//        insert(root, value);
//    }
//    void inorderPrint()
//    {
//        inorder(root);
//        cout << endl;
//    }
//
//    Node* search(int key)
//    {
//        return search(root, key);
//    }
//
//    int height_check()
//    {
//        return height_check(root);
//    }
//    ~BST()
//    {
//        delete_function(root);
//    }
//};
//
//int main() {
//    BST newnode1;
//    newnode1.insert(50);
//    newnode1.insert(30);
//    newnode1.insert(70);
//    newnode1.insert(20);
//    newnode1.insert(40);
//    newnode1.insert(60);
//    newnode1.insert(80);
//    cout << "Inorder traversal data ";
//    newnode1.inorderPrint();
//    Node* searchnode = newnode1.search(40);
//    if (searchnode)
//    {
//        cout << "Data is " << searchnode->data << endl;
//    }
//    else
//    {
//        cout << "Data is not found" << endl;
//    }
//    cout << "Height of the BST tree: " << newnode1.height_check() << endl;
//
//    return 0;
//}
