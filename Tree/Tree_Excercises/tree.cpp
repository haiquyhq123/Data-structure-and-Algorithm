#include<bits/stdc++.h>
using namespace std;

void addEdge(int x, int y, vector<vector<int>>& tree){
    tree[x].push_back(y);
    tree[y].push_back(x);
}
void Printparrentnode(int node, vector<vector<int>>& tree, int parrent){
    if(parrent == 0){
        cout<<node<<"->Root"<<endl;
    }
    else{
        cout<<node<<"->"<<parrent<<endl;
    }
    // DFS
    for(auto i: tree[node]){
        if(i!=parrent){
            Printparrentnode(i,tree,node);
        }
    }
}
void Childrennode(int Root,vector<vector<int>>& tree){
    queue<int> q;
    int vis[tree.size()] = {0};
    q.push(Root);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node] = 1;
        cout<<node<<"->";
        for(auto i: tree[node]){
            if(vis[i]==0){
                cout<<i<<" ";
                q.push(i);
                
            }
        }
        cout<<endl;
    }

}
void Leafnode(int Root, vector<vector<int>>& tree){
    for(int i = 1; i<tree.size(); i++){
        if(tree[i].size()==1 && i!=Root){
            cout<<i<<" ";
        }
    }

}
void Degree(int Root, vector<vector<int>>& tree){
    int vis[tree.size()] = {0};
    for(int i = Root; i<tree.size(); i++){
        vis[i] = 1;
        cout<<i<<":";
        int so = 0;
        for(int j = 0; j<tree[i].size();j++){
            if(vis[tree[i][j]]==0){
                so++;
            }
        }
        cout<<" "<<so;
        cout<<endl;
        
    }
}



int main(){
    int Level = 7, Root = 1;
    vector<vector<int>> tree(Level+1,vector<int>());
    // creating tree
    addEdge(1, 2, tree);
    addEdge(1, 3, tree);
    addEdge(1, 4, tree);
    addEdge(2, 5, tree);
    addEdge(2, 6, tree);
    addEdge(4, 7, tree);
    Degree(Root,tree);

}