class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<int>bucket[100001];
        for(auto mp_val : mp){
            bucket[mp_val.second].push_back(mp_val.first);
        }

        vector<int>result;
        for(int i=100000;i>=0 && k>0;i--){
            for(int j=0;j<bucket[i].size() && k>0;j++,k--){
                result.push_back(bucket[i][j]);
            }
        }

        return result;
    }
};
