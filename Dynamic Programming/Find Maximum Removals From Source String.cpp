class Solution {
public:
    int solve(string &source,string &pattern,int n,int m,vector<int>&check,vector<vector<int>>&memo){
        if(m==0 && n==0)return 0;

        if(m==0 && n!=0){
           int cnt=0;
           for(int i=0;i<n;i++){
             cnt += check[i];
           }
           
           return cnt;
        } 
        
        if(n==0)return INT_MIN;
        
        if(memo[n][m]!=-1)return memo[n][m];

        if(source[n-1]==pattern[m-1]){
            int res = solve(source,pattern,n-1,m-1,check,memo);
            int res1 = solve(source,pattern,n-1,m,check,memo);

            if(res1!=INT_MIN){
                if(check[n-1]==1){
                    res1 = res1+1;
                }
            }
              
            return memo[n][m] = max(res,res1);
        }else{
            int res = solve(source,pattern,n-1,m,check,memo);
             if(res!=INT_MIN){
                if(check[n-1]==1){
                    res = res+1;
                }
            }

            return memo[n][m] = res;
        }
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.length();
        int m = pattern.length();

        vector<int>check(n,0);
        
        for(int i=0;i<targetIndices.size();i++){
            check[targetIndices[i]]=1;
        }
        
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        return solve(source,pattern,n,m,check,memo);
    }
};
