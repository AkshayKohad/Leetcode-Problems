class Solution {
public:
    
   int solve(int i,int j,int player,vector<int>&piles,vector<vector<vector<int>>>&memo)
    {
        if(i>j)
            return 0;
        
       
       if(memo[i][j][player]!=-1)
           return memo[i][j][player];
       
        if(player==0)
        {
            return  memo[i][j][player] = max(piles[i]+solve(i+1,j,1,piles,memo),piles[j]+solve(i,j-1,1,piles,memo));
        }
        
        else if(player==1)
        {
            return memo[i][j][player] = min(solve(i+1,j,0,piles,memo),solve(i,j-1,0,piles,memo));
        }
        
        return 0;
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int sum = 0;
        
        int n = piles.size();
        
        for(int i=0;i<n;i++)
        {
            sum += piles[i];
        }
        
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
       int alice =  solve(0,n-1,0,piles,memo);
        
        int bob = sum - alice;
        
        if(alice>bob)
            return true;
        
        
        
        return false;
    }
};
