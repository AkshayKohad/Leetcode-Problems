class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>nums(32,0);
        for(auto candidate : candidates){
            for(int i=0;i<32;i++){
                int bit = (candidate>>i)&1;
                nums[i]+=bit;
            }
        }

        int maximumResult = 0;
        for(auto num : nums){
            maximumResult = max(maximumResult,num);
        }

        return maximumResult;
    }
};

