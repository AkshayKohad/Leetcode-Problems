class Solution {
public:
    
    bool isPalindrome(int low,int high,string &s){
        while(low<high){
            if(s[low++]!=s[high--]){
                return false;
            }
        }
        return true;
    }
    
    
//    int solve(int i,int n,string s,vector<int>&memo,vector<vector<int>>&memo_palin)
//     {
//         if(i==n)
//             return 0;
        
//         if(memo[i]!=-1)
//             return memo[i];
        
        
//         int res = INT_MAX;
//         for(int j=i;j<n;j++)
//         {
//             if(isPalindrome(i,j,s))
//             {
//                 res = min(res,1+solve(j+1,n,s,memo,memo_palin));
//             }
//         }
        
//         return memo[i] = res;
//     }
    
    
    int minCut(string s) {
        
        int n = s.length();
      //  vector<int>memo(n+1,-1);
       
       // return solve(0,n,s,memo,memo_palin)-1;
        
        int dp[n+1];
        
        dp[n] = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            
            int res = INT_MAX;
            
            
            for(int j=i;j<n;j++)
            {
              if(isPalindrome(i,j,s))
              {
                  int temp = 1 + dp[j+1];
                  
                  res = min(res,temp);
              }
                
                
            }
            
            dp[i] = res;
        }
        
      return dp[0]-1; 
    }
};


	

		
	
