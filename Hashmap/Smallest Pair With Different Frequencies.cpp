class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;

        for(auto num : nums){
            mp[num]++;
        }

        int first_num = -1;

        for(auto num : nums){
            if(first_num==-1){
                first_num = num;
                continue;
            }

            if(mp[first_num]!=mp[num])return {first_num,num};
            
        }

        return {-1,-1};
    }
};
