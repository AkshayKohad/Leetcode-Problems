class Solution {
public:
    
    int dp[1001][26][26];
    
    void reset()
    {
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<26;k++)
                {
                     dp[i][j][k] = -1;
                    
                }
            }
        }
    }
    
    int solve(int i,int &N,vector<string>&words,int first_character,int last_character)
    {
        if(i==N)
        {
            return 0;
        }
        

        
        if(dp[i][first_character][last_character]!=-1)
            return dp[i][first_character][last_character];
        
        
        string k = words[i];
        
        
       
        int m = k.length();
        
        int res;
        if(last_character + 'a' == k[0])
        res = m-1 + solve(i+1,N,words,first_character,k[m-1]-'a');
        
        else{
            res = m + solve(i+1,N,words,first_character,k[m-1]-'a');
        }
        
        int res1;
        
        if(k[m-1] == first_character + 'a')
        res1 = m-1 + solve(i+1,N,words,k[0]-'a',last_character);
        
        else{
            res1 = m + solve(i+1,N,words,k[0]-'a',last_character);
        }
        
        
        
       
        
        return dp[i][first_character][last_character] =  min(res,res1);
        
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        
        reset();
        int n = words.size();
        
        
        int m = words[0].length();
        
      
        int ch = words[0][m-1] - 'a';
        int ch2 = words[0][0] - 'a';
        return m + solve(1,n,words,ch2,ch);
     return 0;   
    }
};
