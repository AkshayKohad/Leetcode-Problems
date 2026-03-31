class Solution {
public:
    int solve(int i,int j, int &n,int &m,vector<vector<int>>&grid,int res,vector<vector<vector<int>>>&memo){
        if(i==n-1 && j==m-1){
            return res;
        }

        if(memo[i][j][res]!=-1)return memo[i][j][res];
        int ans = 1024;
        if(i+1<n){
            int val = solve(i+1,j,n,m,grid,res ^ grid[i+1][j],memo);

            if(val != 1024){
                ans = min(ans,val);
            }
            
        } 
        if(j+1 < m){
            int val = solve(i,j+1,n,m,grid,res ^ grid[i][j+1],memo);

            if(val != 1024){
                ans = min(ans,val);
            }
        }

        return memo[i][j][res] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 1024;
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return solve(0,0,n,m,grid,grid[0][0],memo);

    }
};
