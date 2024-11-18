class Solution {
public:
    #define ll long long

    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        ll sum = 0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        
        ll result = n+1;
        for(ll i=0;i<n;i++){
            sum += nums[i];
            if(sum>=k){
                result = min(result,i+1);    
            }
            while(pq.size()>0 && sum-pq.top().first>=k){
                result = min(result,i-pq.top().second);
                pq.pop();
            }

            pq.push({sum,i});
        }
         if(result==n+1)return -1;

         return result;
    }
};
