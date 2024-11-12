class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long result = 0;
        int l = 0;
        int n = nums.size();
        int cnt_pairs = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            cnt_pairs += mp[nums[i]]-1;
            while(l<i && cnt_pairs>=k){
                result += (nums.size()-i);
                mp[nums[l]]--;
                cnt_pairs -= mp[nums[l]];
                l++;
            }
        }
        return result;
    }
};
