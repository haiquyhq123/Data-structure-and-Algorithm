class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // two pointer basic
        // typical
        vector<int> res;
        int i = 0;
        int j = numbers.size()-1;
        while(j>i){
            if(numbers[i]+numbers[j]>target){
                j--;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else{
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
        }
        return res;   
    }
};