#include<iostream>
using namespace std;
struct Node
{
    int value;
    Node* left;
    Node* right;
};
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->value = data;
    newNode->right = newNode->left = nullptr;
    return newNode;
}
void BFS(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->value<<" ";
    BFS(root->left);
    BFS(root->right);
}
Node* AddNode(Node* root, int val){
    if(root==nullptr){
        root = createNode(val);
        return root;
    }
    if(val>root->value){
        root->right = AddNode(root->right,val);
    }
    else{
        root->left = AddNode(root->left,val);
    }
    return root;

}
int main(){
    int mang[] = {50,20,70,5,12,6,7};
    Node* root = nullptr;
    for(int i = 0; i<7;i++){
        root = AddNode(root, mang[i]);
    }
    BFS(root);
}