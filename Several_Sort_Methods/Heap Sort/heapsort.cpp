#include<bits/stdc++.h>
using namespace std;

void heapify(int mang[], int n, int root){
    int l = 2*root+1;
    int r = 2*root+2;
    int largest = root;
    if(l < n && mang[l]>mang[largest]){
        largest = l;
    }
    if(r<n && mang[r]>mang[largest]){
        largest = r;
    }
    if(root!=largest){
        swap(mang[root],mang[largest]);
        heapify(mang,n,largest);
    }
}
void heapsort(int mang[], int n){
    for(int i = n/2 - 1; i>=0; i--){
        heapify(mang,n,i);
    }
    for(int i = n-1; i>0; i--){
        swap(mang[0],mang[i]);
        heapify(mang,i,0);
    }
}
int main(){
    freopen("heapsort.in","r",stdin);
    freopen("heapsort.out","w",stdout);
    int n; cin>>n;
    int mang[n+1];
    for(int i = 0; i<n; i++){
        cin>>mang[i];
    }
    heapsort(mang,n);
    for(int i = 0; i<n; i++){
        cout<<mang[i]<<" ";
    }
    
}