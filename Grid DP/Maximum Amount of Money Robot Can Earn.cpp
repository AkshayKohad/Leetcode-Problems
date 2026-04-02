class Solution {
public:
    int solve(int i,int j,int &n,int &m,vector<vector<int>>&coins,int chances,vector<vector<vector<int>>>&memo){
        
        if(i==n-1 && j==m-1){
            if(coins[i][j] < 0 && chances>0) 
                return 0;   // use chance only if beneficial
            return coins[i][j];
        }

        if(memo[i][j][chances]!=-1)return memo[i][j][chances];

        int ans = INT_MIN;   

        if(i+1<n){
           if(coins[i][j]<0){
                if(chances>0){
                    ans = max({ans,
                        solve(i+1,j,n,m,coins,chances-1,memo),
                        solve(i+1,j,n,m,coins,chances,memo) + coins[i][j]
                    });
                }else{
                    ans = max(ans,
                        solve(i+1,j,n,m,coins,chances,memo) + coins[i][j]);
                }
           } 
           else{
                ans = max(ans,
                    solve(i+1,j,n,m,coins,chances,memo) + coins[i][j]);
           }
        }

        if(j+1<m){
            if(coins[i][j]<0){
                if(chances>0){
                    ans = max({ans,
                        solve(i,j+1,n,m,coins,chances-1,memo),
                        solve(i,j+1,n,m,coins,chances,memo) + coins[i][j]
                    });
                }else{
                    ans = max(ans,
                        solve(i,j+1,n,m,coins,chances,memo) + coins[i][j]);
                }
            }
            else{
                ans = max(ans,
                    solve(i,j+1,n,m,coins,chances,memo) + coins[i][j]);
            }
        }

        return memo[i][j][chances] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(m,vector<int>(3,-1)));
        //return solve(0,0,n,m,coins,2,memo);

        int dp[n][m][3];
        dp[n-1][m-1][0] = coins[n-1][m-1];
        dp[n-1][m-1][1] = max(0,coins[n-1][m-1]);
        dp[n-1][m-1][2] = max(0,coins[n-1][m-1]);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                for(int k=0;k<=2;k++){
                    if(i==n-1 && j==m-1)continue;
                    int ans = INT_MIN;

                    if(i+1<n){
                        if(coins[i][j]<0){
                            if(k>0){
                                ans = max({ans,dp[i+1][j][k-1],dp[i+1][j][k]+coins[i][j]});
                            }else{
                                ans = max(ans,dp[i+1][j][k]+coins[i][j]);
                            }
                        }else{
                            ans = max(ans,dp[i+1][j][k]+coins[i][j]);
                        }
                    }

                    if(j+1<m){
                        if(coins[i][j]<0){
                            if(k>0){
                                ans = max({ans,dp[i][j+1][k-1],dp[i][j+1][k]+coins[i][j]});
                            }else{
                                ans = max(ans,dp[i][j+1][k]+coins[i][j]);
                            }
                        }else{
                            ans = max(ans,dp[i][j+1][k]+coins[i][j]);
                        }
                    }

                    dp[i][j][k] = ans;
                }
            }
        }

        return max({dp[0][0][0],dp[0][0][1],dp[0][0][2]}); 
    }
};
