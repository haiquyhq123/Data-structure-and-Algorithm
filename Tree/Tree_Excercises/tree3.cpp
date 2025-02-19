#include<bits/stdc++.h>
using namespace std;
// bfs no recursion using iterative stack
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
vector<int> Inordertraversal(Node* curr){
    vector<int> inorder;
    stack<Node*> s;
    while(true){
        if(curr!=nullptr){
            s.push(curr);
            curr = curr->left;
        }
        else{
            if(s.empty()) break;
            curr = s.top();
            inorder.push_back(curr->data);
            s.pop();
            curr = curr ->right;
        }
    }
    return inorder;

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
    for(auto i:Inordertraversal(root)){
        cout<<i<<" ";
    }
    return 0;
}