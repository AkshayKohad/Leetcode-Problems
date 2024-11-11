class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
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
};
