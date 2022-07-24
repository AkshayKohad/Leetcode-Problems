// Approach 1-> LIS (O(n^2))
class Solution {
public:
    
    static bool mycmp(vector<int>f,vector<int>s)
    {
        if(f[0]==s[0])
            return f[1]<s[1];
        
        return f[0]<s[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),mycmp);
        int n = envelopes.size();
        vector<int>dp(n,1);
        
        for(int i=1;i<n;i++)
        {
            
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1])
                {
                    dp[i] = max(1+dp[j],dp[i]);
                }
            }
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            res = max(res,dp[i]);
        }
        
        return res;
        
        
    }
};



// Aprroach 2  LIS -> O(N*LOG(N))

class Solution {
public:
    
    static bool mycmp(vector<int>&f,vector<int>&s)
    {
        if(f[0]==s[0])
            return f[1]>s[1];
        
        return f[0]<s[0];
    }
    
    int binary_search(vector<int>a,vector<int>&ans)
    {
        int l = 0;
        int r = ans.size()-1;
        int mid;
        while(l<=r)
        {
            
             mid = (l+r)/2;
           if(ans[mid]>a[1])
               r = mid-1;
            
            else if(ans[mid]<a[1])
                l = mid+1;
            
            else 
                return mid;
            
        }
        
        return l;
    }
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        
        sort(envelopes.begin(),envelopes.end(),mycmp);
        int n = envelopes.size();
       
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        int count = 1;
        for(int i=1;i<n;i++)
        {
            if(envelopes[i][1]>ans.back())
            {
                ans.push_back(envelopes[i][1]);
                count++;
            }
            
            else{
                int index = binary_search(envelopes[i],ans);
                
            
                ans[index] = envelopes[i][1];
            }
        }
        
        return count;
        
        
    }
};
