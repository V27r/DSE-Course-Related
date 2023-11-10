#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* llink;
    Node* rlink;
};
Node* insert(Node* root,int d){
    Node* temp = new Node();
    temp->data = d;
    temp->llink = temp->rlink = NULL;
    if(root==NULL){
        root = temp;
        return root;
    }
    if(d<root->data){
        root->llink = insert(root->llink,d);
    }
    else{
        root->rlink = insert(root->rlink,d);
    }
    return root;

}
Node* searchBST(Node* root,int target){
    if(root==NULL){
        return root;
    }
    if(target<root->data){
        root->llink = searchBST(root->llink,target);
    }
    else if(target>root->data){
        root->rlink = searchBST(root->rlink,target);
    }
    else{
        cout<<"\n"<<endl;
        cout<<"Target Found: "<<target<<endl;
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
int main(){
    Node* root = NULL;
    cout<<"Binary Search Tree"<<endl;
    char ch= 'y';
    while(ch=='y'){
        cout<<"Enter the element you want to insert: ";
        int e;
        cin>>e;
        root = insert(root,e);
        cout<<"Do u want to continue?(y/n)"<<endl;
        cin>>ch;
    }
    cout<<"Enter the element you want to search: ";
    int ele;
    cin>>ele;
    root = searchBST(root,ele);
}
