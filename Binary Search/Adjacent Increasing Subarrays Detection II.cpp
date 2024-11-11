class Solution {
public:
    bool check(int k,vector<int>&nums){
        if(k==0)return true;
        int i=0;
        int n = nums.size();
        vector<int>res;
        while(i<n){
            int j=i+1;
            int cnt=1;
            while(j<n && nums[i]<nums[j]){
                cnt++;
                i=j;
                j++;
            }
            i=j;
            res.push_back(cnt);
        }
        int m = res.size();
        for(int i=0;i<m-1;i++){
            int val = res[i];
            if(val>=2*k)return true;

            int val1 = res[i+1];

            if(val>=k && val1>=k)return true;
        }
        if(res[m-1]>=2*k)return true;
        return false;
    }
    
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n;
        int ans = -1;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(check(mid,nums)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};
