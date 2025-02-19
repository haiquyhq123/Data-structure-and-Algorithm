#include<bits/stdc++.h>
using namespace std;
void thuchien(char dau, vector<int> &toanhang){
    int s1 = toanhang.back(); toanhang.pop_back();
    int s2 = toanhang.back(); toanhang.pop_back();
    if(dau=='+'){
        toanhang.push_back(s2+s1);
    }
    else{
        toanhang.push_back(s2-s1);
    }

}
// cong tru bang stack
void solve(string s){
    vector<int> toanhang;
    vector<char> toantu;
    for(int i = 0; i<s.size(); i++){
        if(isdigit(s[i])){
            int num = 0;
            while(isdigit(s[i]) && i<s.size()){
                num = 10*num + '0'-s[i];
                i++;
            }
            toanhang.push_back(num);
            i--;
        }
        else{
            if(!toantu.empty()){
                thuchien(s[i],toanhang);
                toantu.pop_back();
                
            }
            toantu.push_back(s[i]);
        }
    }
    if(!toantu.empty()){
        thuchien(toantu.back(),toanhang);

    }
    cout<<toanhang.back();
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("stack_exercise1.in", "r", stdin);
        freopen("stack_exercise1.out", "w", stdout);
    #endif
    string s; cin>>s;
    solve(s);
    return 0;
}