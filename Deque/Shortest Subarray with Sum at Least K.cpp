class Solution {
public:
    #define ll long long

    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<ll,ll>>dq;
        ll n = nums.size();
        ll pref_sum = 0;
        ll result = n+1;
        for(ll i=0;i<n;i++){
            pref_sum += nums[i];

            if(pref_sum>=k)result = min(result,i+1);

            while(dq.size()>0 && pref_sum-dq.front().first>=k){
                result = min(result,i-dq.front().second);
                dq.pop_front();
            }

            while(dq.size()>0 && dq.back().first>=pref_sum){
                dq.pop_back();
            }
            dq.push_back({pref_sum,i});
        }
        if(result==n+1)return -1;
        return result;
    }
};
