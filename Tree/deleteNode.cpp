#include<iostream>
using namespace std;
struct Node
{
    int value;
    Node* left;
    Node* right;
};
Node* createNode(int val){
    Node* newNode = new Node();
    newNode->value = val;
    newNode->left = newNode -> right = nullptr;
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
Node* deleteNode(Node* root, int k)
{
    // Base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in the left subtree
    if (k < root->value) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    // If the value to be deleted is greater than the root's key,
    // then it lies in the right subtree
    else if (k > root->value) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    // If key is same as root's key, then this is the node to be deleted
    // Node with only one child or no child
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest
    // in the right subtree)
    Node* succParent = root;
    Node* succ = root->right;
    while (succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
    }

    // Copy the inorder successor's content to this node
    root->value = succ->value;

    // Delete the inorder successor
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;
    
    delete succ;
    return root;
}

int main(){
    int mang[] = {50,20,70,5,12,6,7};
    Node* root = nullptr;
    for(int i = 0; i<7;i++){
        root = AddNode(root, mang[i]);
    }
    // deleteNode(root,12);
    BFS(root);

    return 0;
}