class Solution {
public:
    int LIS(vector<int>&cur){
        vector<int>res;

        for(int i=0;i<cur.size();i++){
            if(res.size()==0 || res.back()<cur[i]){
                res.push_back(cur[i]);
            }else{
                auto it = lower_bound(res.begin(),res.end(),cur[i]);
                *it = cur[i];
            }
            
        }
        return res.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<31;i++){
            vector<int>curr;
            for(auto num : nums){
                int val = (num>>i)&1;

                if(val)curr.push_back(num);
            }

            result = max(result,LIS(curr));
        }

        return result;
    }
};
