class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int i=0;
        int result = n;
        while(i<n){
            int ind = lower_bound(nums.begin(),nums.end(),(long long)nums[i]*k) - nums.begin();

            if(ind == nums.size()){
                result = min(result,i);
            }else{
                long long val = nums[ind];
                if(val>(long long)nums[i]*k){
                     result = min(result,i+n-ind);
                }else{
                     result = min(result,i+n-(ind+mp[val]));
                }
            }
            

            int j=i;
            while(j<n && nums[j]==nums[i]){
                j++;
            }
            i=j;
        }
        return result;
    }
};
