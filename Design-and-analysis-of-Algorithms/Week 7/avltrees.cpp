#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int val) 
	{
        data = val;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

class AVLTree 
{
public:
    Node* root;
    AVLTree() 
	{
        root = NULL;
    }
    int height(Node* node) 
	{
        if (node == NULL) 
            return 0;
        return node->height;
    }
    int balanceFactor(Node* node) 
	{
        if (node == NULL) 
            return 0;
        return height(node->left) - height(node->right);
    }
    void updateHeight(Node* node) 
	{
        node->height = max(height(node->left), height(node->right)) + 1;
    }
    Node* rotateRight(Node* node) 
	{
        Node* newRoot = node->left;
        Node* temp = newRoot->right;
        newRoot->right = node;
        node->left = temp;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }
    Node* rotateLeft(Node* node) 
	{
        Node* newRoot = node->right;
        Node* temp = newRoot->left;
        newRoot->left = node;
        node->right = temp;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }
    Node* insert(Node* node, int val) 
	{
        if (node == NULL) 
            return new Node(val);
        if (val < node->data) 
            node->left = insert(node->left, val);
        else 
            node->right = insert(node->right, val);
        updateHeight(node);
        int balance = balanceFactor(node);
        if (balance > 1 && val < node->left->data) 
            return rotateRight(node);
        if (balance < -1 && val > node->right->data)
            return rotateLeft(node);
        if (balance > 1 && val > node->left->data)
		{
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && val < node->right->data) 
		{
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    void inorderTraversal(Node* node) 
	{
        if (node == NULL) 
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
};

int main() 
{
    AVLTree tree;
    int i, n, x;
    cout<<"Enter number of elements:";
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>x;
    	tree.root = tree.insert(tree.root, x);	
	}   
    tree.root = tree.insert(tree.root, 6);
    cout << "Inorder traversal of the avl tree:\n";
    tree.inorderTraversal(tree.root);
    return 0;
}