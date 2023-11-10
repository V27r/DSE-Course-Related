#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* llink;
    Node* rlink;
};
Node* insert(Node* root,int data){
    Node* temp = new Node;
    temp->data = data;
    temp->llink=temp->rlink=NULL;
    if(root==NULL){
        root = temp;
        return root;
    }
    Node* i= root;
    char str[10];
    while(i!=NULL){
        cout<<"Insert left or right of "<<i->data<<"?"<<endl;
        cin>>str;
        if(strcmp(str,"left")==0){
            if(i->llink==NULL){
                i->llink = temp;
                break;
            }
            else{
                i= i->llink;
            }
        }
        else{
            if(i->rlink==NULL){
                i->rlink=temp;
                break;
            }
            else{
                i = i->rlink;
            }
        }
    }
    return root;

}
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->llink);
        cout<<root->data<<" ";
        inorder(root->rlink);
    }
}
void preorder(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(Node* root){
    if(root!=NULL){
        postorder(root->llink);
        postorder(root->rlink);
        cout<<root->data<<" ";
    }
}
int count_leaves(Node* root){
    if(root==NULL){
        return 0;
    }
    else if(root->llink==NULL && root->rlink==NULL){
        return 1;
    }
    else{
         return count_leaves(root->llink)+count_leaves(root->rlink);
    }
}
void parent(Node* root,int val,int p){
    if(root==NULL){
        return;
    }
    if(root->data ==val){
        cout<<p<<endl;
    }
    else{
        parent(root->llink,val ,root->data);
        parent(root->rlink,val ,root->data);
    }
}
int depth(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int c1 = depth(root->llink)+1;
        int c2 = depth(root->rlink)+1;

        if(c1>c2){
            return c1;
        }
        else{
            return c2;
        }
    }

    
}
int Ancestors(Node* root,int val){
    if(root==NULL){
        return false;
    }
    if(root->data==val){
        return true;
    }
    if(Ancestors(root->llink,val)||Ancestors(root->rlink,val)){
        cout<<root->data<<" ";
        return true;
    }
    else{
        return false;
    }
}
int main(){
    Node* root = NULL;
    cout<<"Creation of Binary Tree"<<endl;
    char ch= 'y';
    while(ch=='y'){
        cout<<"Enter the element you want to insert: ";
        int e;
        cin>>e;
        root = insert(root,e);
        cout<<"Do u want to continue?(y/n)"<<endl;
        cin>>ch;
    }
    ch = 'y';
    while(ch=='y'){
        cout<<"1.Inorder traversal\n2.Preorder Traversal\n3.Postorder Traversal\n4.Count of leaf nodes\n5.Parent of Given element\n6.Depth of tree\n7.Ancestor of given node"<<endl;
    int x;
    cout<<"Enter your input:";
    cin>>x;
    switch (x)
    {
    case 1:
        inorder(root);
        break;
    case 2:
        preorder(root);
        break;
    case 3:
        postorder(root);
        break;
    case 4:
        cout<<"The no. of leaf nodes = "<<count_leaves(root)<<endl;
        break;
    case 5:
        cout<<"Enter the element: ";
        int d;
        cin>>d;
        cout<<"The parent of "<<d<<" = ";
        parent(root,d,-1);
        break;
    case 6:
        cout<<"The depth of tree = "<<depth(root);
        break;
    case 7:
        cout<<"Enter the element: ";
        int k;
        cin>>k;
        cout<<"Ancestors of the given element: "<<Ancestors(root,k);
        break;
    default:
        break;
    }
    cout<<"\nDo u want to continue?(y/n)"<<endl;
    cin>>ch;
    }
}
