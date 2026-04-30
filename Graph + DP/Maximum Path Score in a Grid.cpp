class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1}};
    int solve(int i,int j,int &n,int &m,vector<vector<int>>& grid,int cur_cost,int &k,vector<vector<vector<int>>>&memo){
        
        if(cur_cost>k)return INT_MIN;

        if(i==n-1 && j==m-1){
           return 0;
        }

        if(memo[i][j][cur_cost] != -1)return memo[i][j][cur_cost];

        int result = INT_MIN;
        for(auto u : directions){
            int x = i + u.first;
            int y = j + u.second;

            if(x>=n || y>=m)continue;

            int val1 = solve(x,y,n,m,grid,cur_cost + (grid[x][y] == 0 ? 0 : 1),k,memo);
            
            if(val1 != INT_MIN)val1 += grid[x][y];

            result = max(result,val1);
        }
       
        return memo[i][j][cur_cost] = result; 
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int result = solve(0,0,n,m,grid,0,k,memo);

        return result == INT_MIN ? -1 : result;
    }
};
