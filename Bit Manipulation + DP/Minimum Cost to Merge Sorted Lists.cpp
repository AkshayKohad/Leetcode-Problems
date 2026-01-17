class Solution {
public:
    #define ll long long
    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();
        int sz = (1<<n);
        vector<vector<int>>arr(sz);
        vector<ll>dp(sz,1e18);
        vector<int>len(sz);
        vector<int>median(sz);

        for(int i=0;i<n;i++){
            arr[1<<i] = lists[i];
            int m = lists[i].size();
            len[1<<i] = m;
            median[1<<i] = lists[i][(lists[i].size()-1)/2];
            dp[1<<i] = 0;
        }

        for(int mask=1;mask<sz;mask++){
            if((mask&(mask-1)) == 0)continue;

            int b = mask&-mask;
            int r = mask^b;

            arr[mask].resize(arr[b].size()+arr[r].size());
            merge(arr[b].begin(),arr[b].end(),arr[r].begin(),arr[r].end(),arr[mask].begin());
            len[mask] = arr[mask].size();
            median[mask] = arr[mask][(len[mask]-1)/2];
        }

        for(int mask=1;mask<sz;mask++){
            if((mask&(mask-1)) == 0)continue;

            for(int sub = (mask&(mask-1)); sub; sub = (sub-1)&mask){
                int oth = sub ^ mask;

                dp[mask] = min(dp[mask], dp[oth]+dp[sub]+len[oth]+len[sub]+abs(median[sub]-median[oth]));
            }
        }

        return dp[sz-1];
    }
};
