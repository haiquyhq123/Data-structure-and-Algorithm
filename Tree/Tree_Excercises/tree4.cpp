#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
void bfs(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    bfs(root->left);
    bfs(root->right);
}
Node* Insert(Node* root, int val){
    if(root==nullptr){
        // if(val>root->data){
        //     root->right = createNode(val);
        //     return root;
        // }
        // else{
        //     root->left = createNode(val);
        //     return root;
        // }
        root = createNode(val);
        return root;
    }    
    if(val>root->data){
        root->right = Insert(root->right,val);
    }
    else if(val<root->data){
        root->left = Insert(root->left,val);
    }
    return root;
}
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->left->right = createNode(4);
    root->left->left = createNode(3);
    root->left->left->left = createNode(5);
    root->left->left->left->right = createNode(6); 
    root->left->left->left->right->right = createNode(10);
    root->right = createNode(7);
    root->right->left = createNode(9);
    root->right->right = createNode(8);
    bfs(root);
    Insert(root,50);
    
    return 0;
}