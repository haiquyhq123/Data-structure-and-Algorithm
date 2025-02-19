#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Main idea is sum of vector
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("YoungPhysicist.in","r",stdin);
        freopen("YoungPhysicist.out","w",stdout);
    #endif 
    ll n;
    cin>>n;
    int m[101][3];
    for(ll i = 0; i<n; i++){
        cin>>m[i][0]>>m[i][1]>>m[i][2];
    }
    int cur[3];
    cur[0] = m[0][0];
    cur[1] = m[0][1];
    cur[2] = m[0][2];
    for(ll i = 1; i<n; i++){
        cur[0]+=m[i][0];
        cur[1]+=m[i][1];
        cur[2]+=m[i][2]; 
    }
    if(cur[0]==0 && cur[1]==0 && cur[2]==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}