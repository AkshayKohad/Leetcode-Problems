class Solution {
public:
    
    #define ll long long 
    
    #define mod 1000000007
    
    ll dp[101][11][2][2];
    
    void reset()
    {
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<11;j++)
            {
                for(int k=0;k<2;k++)
                {
                    for(int l=0;l<2;l++)
                    {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
    }
    
    
    ll solve(string &num,int cur_index,int prev_digit,bool is_limit,bool iszero)
    {
        if(num.length()==cur_index)
        {
            return iszero ? 0:1;
        }
        
        if(dp[cur_index][prev_digit+1][iszero ? 1:0][is_limit ? 1:0]!=-1)
            return dp[cur_index][prev_digit+1][iszero ? 1:0][is_limit ? 1:0];
            
        int limit = num[cur_index]-'0';
        
        if(!is_limit)
        {
            limit = 9;
        }
        
        ll res = 0;
        for(int index = 0;index<=limit;index++)
        {
            bool next_is_limit = is_limit && (index==limit);
            bool next_iszero = iszero && (index==0);
            
          //  int digit = num[cur_index]-'0';
            
            if(iszero || (abs(index-prev_digit) == 1))
            {
                res = (res + solve(num,cur_index+1,index,next_is_limit,next_iszero))%mod;
            }
        }
        
       return dp[cur_index][prev_digit+1][iszero ? 1:0][is_limit ? 1:0] = res;
    }
    int countSteppingNumbers(string low, string high) {
  
        reset();
            
       ll result =  solve(high,0,-1,true,true);  
        
        reset();
        
         result -= solve(low,0,-1,true,true);
        
       
        result = (result+mod)%mod;
        
        bool is_low_valid = true;
        
        for(int i=1;i<low.length();i++)
        {
            int cur_digit = low[i] - '0';
            int prev_digit = low[i-1] - '0';
            
            if(abs(cur_digit-prev_digit)!=1)
            {
                is_low_valid = false;
                break;
            }
            
        }
        
         result = (result  + (is_low_valid ? 1:0))%mod;
        
        return result;
    }
};
