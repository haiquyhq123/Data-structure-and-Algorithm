#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    ll ar[100];
    for(ll i = 0; i<n;i++){
        cin>>ar[i];
    }
    for(ll i = 1; i<n;i++){
        ll key = ar[i];
        ll j = i - 1;
        while(j>=0 && key <= ar[j]){
            // to change direction replace >=
            ll temp = ar[j];
            ar[j] = key;
            ar[j+1] = temp;
            j--;
        }
    }
    for(ll i =0; i<n; i++){
        cout<<ar[i]<<" ";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("intersection_sort.in","r",stdin);
        freopen("intersection_sort.out","w",stdout);
    #endif 
    solve();
    return 0;
}