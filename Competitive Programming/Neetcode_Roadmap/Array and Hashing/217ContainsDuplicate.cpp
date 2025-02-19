class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int ban_dau = nums.size();
        set<int> st;
        for(int i=0; i<=ban_dau-1;i++){
            st.insert(nums[i]);
        }
        if(st.size()!=ban_dau){
            return true;
        }
        else{
            return false;
        }
        
    }
};