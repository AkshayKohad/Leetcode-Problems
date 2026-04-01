class Solution {
public:
    #define MOD 1000000007

    int countArrays(vector<int>& digitSum) {

     vector<vector<int>>pos(32);
     for(int i=0;i<=5000;i++){
        int num = i;
        int sum = 0;
        while(num>0){
            sum += num%10;
            num = num/10;
        }

        pos[sum].push_back(i);
     }

    int x = digitSum[0];
    if(x>31)return 0;
    
    int n = digitSum.size();
    vector<long long>dp(5001,0);
    

    for(auto val : pos[x]){
        dp[val] = 1;
    }
     for(int i=1;i<n;i++){
        vector<long long>ndp(5001,0);
        vector<long long>prefix_dp(5001,0);
        prefix_dp[0] = dp[0];
        for(int i=1;i<=5000;i++){
            prefix_dp[i] = (prefix_dp[i-1]+dp[i])%MOD;
        }
        if(digitSum[i]<=31){
            vector<int>v;
            int prev = digitSum[i-1];
            vector<int>temp = prev <= 31 ? pos[prev] : v;
            
            for(auto val : pos[digitSum[i]]){
                long long ans = 0;
                ans = prefix_dp[val];
                // Used prefix instead of loop to optimize
                // for(auto it : temp){
                //     if(it>val)break;

                //     ans = (ans + dp[it])%MOD;
                // }
                ndp[val] = ans;
            }
        }
        dp = ndp;

     }

     long long result = 0;
     int dsum = digitSum[n-1];
     if(dsum > 31)return 0;
     
     for(auto val : pos[digitSum[n-1]])
        result = (result + dp[val])%MOD;

     return result;

    }
    
};
