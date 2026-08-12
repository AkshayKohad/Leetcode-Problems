class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int res = 0;
        while(j<n){
            if(mp[nums[j]]<k){
                mp[nums[j]]++;
                j++;
            }else{
                while(mp[nums[j]]==k){
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[j]]++;
                j++;
            }
            res = max(res,j-i);
            
        }
        return res;
    }
};
