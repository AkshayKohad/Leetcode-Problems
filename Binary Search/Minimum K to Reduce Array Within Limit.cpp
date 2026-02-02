class Solution {
public:
    bool check(long long k,vector<int>&nums){
        long long res_cnt = 0;
        for(auto num : nums){
            res_cnt += (num/k) + (num%k > 0 ? 1 : 0);
        }

        if(sqrt(res_cnt) > k)return false;
        return true;
    }
    int minimumK(vector<int>& nums) {
        long long maximum = 0;
        for(auto num : nums){
            maximum += num; 
        }
        

        long long l=1;
        long long r=maximum;
        long long ans = -1;
        while(l<=r){
            long long mid = (r-l)/2 + l;

            if(check(mid,nums)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
