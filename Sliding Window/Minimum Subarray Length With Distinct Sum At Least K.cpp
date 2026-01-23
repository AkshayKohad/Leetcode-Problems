class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;

        int left = 0;
        int right = 0;
        int sum = 0;
        int result = n+1;
        while(right<n){
            if(mp[nums[right]]==0)
            sum += nums[right];
            
            mp[nums[right]]++;
            if(sum>=k)
            result = min(result,right-left+1);
            

            while(sum>=k){
                result = min(result,right-left+1);
                if(mp[nums[left]]==1)
                sum -= nums[left];

                mp[nums[left]]--;
                left++;
            }

            right++;

        }

        if(result == n+1)return -1;
        return result;
    }
};
