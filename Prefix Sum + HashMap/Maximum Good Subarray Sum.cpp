class Solution {
public:
    #define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<ll,ll>mp;
        ll curSum = 0;
        bool flagStarted = false;
        ll res = 0;
        for(auto num : nums){
            curSum += num;
            if(mp.find(num-k)!=mp.end()){
                ll it_begin = mp[num-k];
                
                if(flagStarted){
                    res = max(res,curSum-it_begin+(num-k));
                }else{
                    res = curSum-it_begin+(num-k);
                    flagStarted = true;
                }
                
            }

            if(mp.find(num+k)!=mp.end()){
                ll it_begin = mp[num+k];
                if(flagStarted){
                    res = max(res,curSum-it_begin+(num+k));
                }else{
                    res = curSum-it_begin+(num+k);
                    flagStarted = true;
                }
            }
            if(mp.find(num)==mp.end())mp[num] = curSum;
            mp[num] = min(mp[num],curSum);
        }

        return res;
    }
};
