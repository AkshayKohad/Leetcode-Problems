class Solution {
public:
    
    int MOD = 1000000007;
    
    int solve(int s,int &endPos,int k,vector<vector<int>>&memo,int &K)
    {
        if(s==endPos && k==0){
            
            return 1;
        }
        
        if(k==0) return 0;
        
        if(memo[s+K][k]!=-1) return memo[s+K][k];
        
        
        return memo[s+K][k] = (solve(s+1,endPos,k-1,memo,K) + solve(s-1,endPos,k-1,memo,K))%MOD;
        
    }
    int numberOfWays(int startPos, int endPos, int k) {
     
       
       
        // we have added 2k+1 beacause for max(startPos,endPos) we will go to K steps to positive side and to handle negative number also we are adding K
        //in our memo vector
        
       vector<vector<int>>memo(max(startPos,endPos)+2*k+1,vector<int>(k+1,-1));
        return solve(startPos,endPos,k,memo,k);
        
     
    }
};
