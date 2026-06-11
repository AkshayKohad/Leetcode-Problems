class Solution {
public:
    int countSubstrings(string s) {
       
    // Replace this placeholder return statement with your code
    int n = s.length();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    int count = 0;
    for(int i=0;i<n;i++){
        dp[i][i] = true;
        count++;
    }
    
    for(int i=0;i<n-1;i++){
        dp[i][i+1] = (s[i]==s[i+1]);
        count += dp[i][i+1];
    }

    for(int length = 3;length <= n; length++){
        for(int i=0,j=length-1;i<n && j<n; i++,j++){
            dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
            count += dp[i][j];
        }
    }
    return count;

    }
};
