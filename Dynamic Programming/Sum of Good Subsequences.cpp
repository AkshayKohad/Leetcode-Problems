class Solution {
public:
#define ll long long
#define mod 1000000007
    int sumOfGoodSubsequences(vector<int>& nums) {
        ll n = nums.size();   
        map<ll,ll>left; 
        vector<ll>left_cnt(n,0);
        ll result = 0;
        int ind = 0;
        for(auto num:nums){
            left[num]+= ((left[num-1] + left[num+1])%mod +1)%mod;
            left_cnt[ind] = ((left[num-1] + left[num+1])%mod + 1)%mod;
            ind++;
        }

        map<ll,ll>right;
        vector<ll>right_cnt(n,0);
        ind = 0;
        reverse(nums.begin(),nums.end());
        for(auto num:nums){
            right[num]+= ((right[num-1] + right[num+1]) + 1)%mod;
            right_cnt[n-1-ind] = ((right[num-1] + right[num+1]) + 1)%mod;
            ind++;
        }
        reverse(nums.begin(),nums.end());
        for(ll i=0;i<n;i++){
            ll cnt_left = left_cnt[i];
            ll cnt_right = right_cnt[i];
            result = (result + (((cnt_left*cnt_right)%mod)*(ll)nums[i])%mod)%mod;
        }
        return result;
    }
};
