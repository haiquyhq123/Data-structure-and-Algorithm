#include<bits/stdc++.h>
using namespace std;
#define ll long long
// The main idea of this problem is that the center point is always at the coordinates (3,3)
//So we should find the coordinates of 1, imagine the shortest path as the edge of a rectangle transformed by the two mentioned points (the center and 1).
// m1 is array, which i use to store coordinates of 1
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("BeautifulMatrix.in","r",stdin);
        freopen("BeautifulMatrix.out","w",stdout);
    #endif
    int m[6][6];
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5;j++){
            cin>>m[i][j];
        }
    }
    int m1[2];
    for(int i =0; i<5; i++){
        for(int j = 0; j<5;j++){
            if(m[i][j]==1){
                m1[0] = i+1;
                m1[1] = j+1;
                break;
            }
        }
    }
    cout<<abs(3-m1[0])+abs(3-m1[1]);
}