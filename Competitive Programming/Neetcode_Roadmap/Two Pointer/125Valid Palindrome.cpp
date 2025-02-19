class Solution {
public:
    // convert 
    string convert(string s){
        string res = "";
        for(int i = 0; i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                res+=tolower(s[i]);
            }
            else if(s[i]>='a' && s[i]<='z'){
                res+=s[i];
            }
            else if(s[i]>='0' && s[i]<='9'){
                res+=s[i];
            }
            
        }
        return res;
    }
    bool isPalindrome(string s) {
        string snew = convert(s);
        // there are two case
        // case 1: number of s is even
        int sizes = snew.size();
        if(sizes%2==0){
            for(int i = 0; i<sizes/2; i++){
                int j = (sizes-1)-i;
                if(snew[i]!=snew[j]){
                    return false;
                }
            }
        } 
        //case 2: odd
        else{
            int i = 0;
            int j = sizes-1;
            while(i!=j){
                if(snew[i]!=snew[j]){
                    return false;
                }
                i++;
                j--;

            }
        }
        return true;
    }
};