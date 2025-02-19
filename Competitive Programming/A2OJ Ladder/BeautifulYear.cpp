#include<bits/stdc++.h>
using namespace std;
#define ll long long
// the main idea is just brute force increase num variable increasing 1 over time 
// then convert it in to string to easily access each number in that string
// you can use hash algo or set because the time complexity is linear which i think it is the best
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("BeautifulYear.in","r",stdin);
        freopen("BeautifulYear.out","w",stdout);
    #endif
    int num; cin>>num;
    num++;
    bool found = false;
    while(found == false){
        string stringnum = to_string(num);
        set<char> st;
        st.insert(stringnum[0]);
        st.insert(stringnum[1]);
        st.insert(stringnum[2]);
        st.insert(stringnum[3]);
        if(st.size() == 4){
            found = true;
        }
        else{
            num++;
        }

    }
    cout<<num;
}