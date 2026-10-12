class Solution {
public:
    bool check(int limit,vector<int>&nums,int k){
        int cur_house = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=limit){
                cur_house++;
                i++;
            }
        }
        if(cur_house>=k)return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1;
        int r = 1e9;
        int ans = -1;
        while(l<=r){
            int mid = (r-l)/2 + l;
            if(check(mid,nums,k)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;   
    }
};
