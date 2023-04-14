class Solution {
public:
    
    #define mod 1000000007
    
    int solve(vector<pair<int,int>>&new_arr,int n,int target,vector<vector<int>>&memo)
    {
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        
        if(n==0)
            return 0;
        
        if(memo[n][target]!=-1)
            return memo[n][target];
        
        int count = new_arr[n-1].first;
        int marks = new_arr[n-1].second;
        
        int result = 0;
        for(int i=1;i<=count;i++)
        {
            result = (result + solve(new_arr,n-1,target-i*marks,memo))%mod;
        }
        
        result = (result + solve(new_arr,n-1,target,memo))%mod;
        
        return memo[n][target] = result%mod;
        
        
        
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        
        vector<pair<int,int>>new_arr;
        
        for(int i=0;i<types.size();i++)
        {
            int count = types[i][0];
            int marks = types[i][1];
            
           new_arr.push_back({count,marks});
            
        }
        
        int n = new_arr.size();
        
        vector<vector<int>>memo(n+1,vector<int>(target+1,-1));
        
        return solve(new_arr,n,target,memo);
    }
};
