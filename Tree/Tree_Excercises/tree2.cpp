#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* createTreeNode(int data){
    TreeNode* newTreeNode = new TreeNode();
    newTreeNode->data = data;
    newTreeNode->left=newTreeNode->right=nullptr;
    return newTreeNode;

}
void bfsnorecursion(TreeNode* root){
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* cur = root;
    while(!st.empty() || cur!=nullptr){
        while(cur!=nullptr){
            st.push(cur);
            cur= cur->left;
        }
        cur = st.top();
        st.pop();
        cout<<cur->data<<" ";
        cur = cur->right;
    }
    

}
int main(){
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->left->right->left= createTreeNode(9);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);
    root->right->right->left = createTreeNode(15);
    bfsnorecursion(root);
    

}