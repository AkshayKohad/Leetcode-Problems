class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{1,1},{1,-1}};
    int solve(int i,int j,int &n,int &m,vector<vector<int>>&matrix,vector<vector<int>>&memo,vector<vector<int>>&visited){
        if(i==n-1){
            return matrix[i][j];
        }
        if(visited[i][j])return memo[i][j];
        visited[i][j] = 1;
        int res = INT_MAX;
        for(auto dir : directions){
            int x = i+dir.first;
            int y = j+dir.second;
            if(x<0 || y<0 || x>=n || y>=m)continue;
            res = min(res,matrix[i][j] + solve(x,y,n,m,matrix,memo,visited));
        }

        return memo[i][j] = res;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        int result = INT_MAX;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            result = min(result,solve(0,j,n,m,matrix,memo,visited));
        }
        return result;
    }
};
