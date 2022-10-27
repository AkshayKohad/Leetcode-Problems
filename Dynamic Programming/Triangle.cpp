class Solution {
public:
    
    int solve(int i,int j,int &n,vector<vector<int>>&triangle,unordered_map<int,unordered_map<int,int>>&memo)
    {
        if(i==n)
            return 0;
        
        if(memo.find(i)!=memo.end() && memo[i].find(j)!=memo[i].end())
            return memo[i][j];
        
        int ans1  = solve(i+1,j,n,triangle,memo);
        int ans2  = solve(i+1,j+1,n,triangle,memo);
        
        return memo[i][j] = triangle[i][j] + min(ans1,ans2);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        unordered_map<int,unordered_map<int,int>>memo;
        
        return solve(0,0,n,triangle,memo);
        
    }
};
