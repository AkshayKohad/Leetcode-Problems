class Solution {
public:

vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};

int solve(int i,int j,vector<vector<int>>&mat,int &n,int &m,vector<vector<int>>&visited,vector<vector<int>>&memo){

    if(memo[i][j]!=-1)return memo[i][j];

    visited[i][j]=1;

    int res = 1;
    for(auto k:directions){
        int x = i+k.first;
        int y = j+k.second;

        if(x<0 || y<0 || x>=n || y>=m)continue;
        if(visited[x][y]==1)continue;
        if(mat[i][j]>=mat[x][y])continue;

        res = max(res,1+solve(x,y,mat,n,m,visited,memo));
    }
    visited[i][j] = 0;
    return memo[i][j] = res;
}

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>memo(n,vector<int>(m,-1));
        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result = max(result,solve(i,j,mat,n,m,visited,memo));
            }
        }

        return result;   
    }
};
