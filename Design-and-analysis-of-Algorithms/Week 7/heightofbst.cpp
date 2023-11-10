#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data)
{
    Node* node=new Node();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int max(int a,int b) 
{
    return (a>=b)?a:b;
}
int treeHeight(Node* node) 
{
    if(node==NULL)
        return 0;
    else 
	{
        int leftHeight=treeHeight(node->left);
        int rightHeight=treeHeight(node->right);
        return max(leftHeight,rightHeight)+1;
    }
}
int main() 
{
    Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    cout<<"Height of tree:"<<treeHeight(root);
    return 0;
}