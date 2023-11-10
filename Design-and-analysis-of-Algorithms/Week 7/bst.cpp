/*
    Implementation of Binary Search Tree
    02 Feb 2023
*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node* newNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

Node* insert(Node* root, int data) 
{
  if (root == NULL) return newNode(data);
  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);
  return root;
}

bool search(Node* root, int data) 
{
  if (root == NULL) return false;
  if (root->data == data) return true;
  if (root->data < data)
    return search(root->right, data);
  else
    return search(root->left, data);
}

void inorder(Node* root) 
{
	if(root!=NULL) 
	{
    	inorder(root->left);
    	cout << root->data << " ";
    	inorder(root->right);
  	}
}

void preorder(Node* root) 
{
 	if (root != NULL)
	{
    	cout << root->data << " ";
    	preorder(root->left);
    	preorder(root->right);
  	}
}

void postorder(Node* root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }
}
int main()
{
	int choice,val;
	Node *root=NULL;
    do
    {
        cout<<"1. Create a node\n";
        cout<<"2. Insert a value if it is not present in the tree\n";
        cout<<"3. Inorder Traversal\n";
        cout<<"4. Preorder Traversal\n";
        cout<<"5. Postorder Traversal\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter value to be inserted at the root:";
                cin>>val;
                root=insert(root,val);
                break;
            case 2:
                cout<<"Enter value to be searched in the tree:";
                cin>>val;
				if(search(root,val))
      				cout<<val<<" is already present\n";
    			else
      				root=insert(root,val);
                break;
            case 3:
                cout<<"Inorder Traversal:\n";
                inorder(root);
                cout<<"\n";
                break;
            case 4:
                cout<<"Preorder Traversal:\n";
                preorder(root);
                cout<<"\n";
                break;
            case 5:
                cout<<"Postorder Traversal:\n";
                postorder(root);
                cout<<"\n";
                break;
            case 6:
                cout<<"Exited!\n";
                break;
            default:
                cout<<"Invalid choice!\n";
        }
    }while(choice!=6);
    return 0;
}
