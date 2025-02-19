#include<bits/stdc++.h>
using namespace std;
#define ll long long
// we just make the condition base on the 0 = "." , 1 = "-.", 2="--"
// we can make sure it will not out the index of the string
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Borze.in","r",stdin);
        freopen("Borze.out","w",stdout);
    #endif
    string s; cin>>s;
    string res = "";
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='.'){
            res+='0';
        }
        else{
            if(s[i+1]=='.'){
                res+="1";
                i++;
            }
            else{
                res+="2";
                i++;
            }
        }
    }
    cout<<res;
}