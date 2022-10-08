class Solution {
public:
    
    int solve(int i,int count,int &n,vector<int>&satisfaction,vector<vector<int>>&memo)
    {
        if(i==n)
            return 0;
        
        if(memo[i][count]!=-1) 
            return memo[i][count];
        
       return memo[i][count] =  max(satisfaction[i]*count + solve(i+1,count+1,n,satisfaction,memo) , solve(i+1,count,n,satisfaction,memo));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        
        int n = satisfaction.size();
        
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        
        return solve(0,1,n,satisfaction,memo);
    }
};
