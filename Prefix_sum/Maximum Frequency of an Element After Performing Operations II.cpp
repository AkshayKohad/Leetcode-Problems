class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<int,int>freq;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            mp[nums[i]]+=0;
            mp[nums[i]-k]+=1;
            mp[nums[i]+k+1]-=1;
        }

        int pref_sum = 0;
        int result = 0;
        for(auto val:mp){
            pref_sum += val.second;

            int required_operations = min(numOperations,pref_sum-freq[val.first]);
            result = max(result,required_operations+freq[val.first]);
        }
        return result;
    }
};
