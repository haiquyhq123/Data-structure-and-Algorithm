#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node* createNode(int data1){
    Node* newNode = new Node();
    newNode->data = data1;
    newNode->right = newNode->left = nullptr;
    return newNode;
}
void printTree(Node* root){
    // dfs postoredr
    if(root == nullptr) return;
    printTree(root->left);
    printTree(root->right);
    cout<<root->data<<" ";
}
void bfs(Node* root){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        cout<<node->data<<" ";
        q.pop();
        if(node->left!=nullptr){
            q.push(node->left);
        }
        if(node->right!=nullptr){
            q.push(node->right);
        }
    }

}
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->left= createNode(9);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->right->left = createNode(15);
    bfs(root);

}