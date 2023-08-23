class Solution {
public:
    
    
    bool check(vector<int>&houses,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(houses[i]!=0) return false;
        }
        
        return true;
    }
    
    void set(vector<int>&houses,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            houses[i]=-1;
        }
    }
    
    
    int binary_search(vector<vector<int>>&offers,int start,int end,vector<int>offer)
    {
        int l = start;
        int r = end;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(offer[1]>=offers[mid][0])
            {
                l = mid+1;
            }
            
            else{
                r = mid-1;
            }
        }
        
        return l;
    }
    int solve(int index,vector<vector<int>>&offers,int &m,vector<int>&memo)
    {
        if(index==m)
            return 0;
        
        if(memo[index+1]!=-1)
            return memo[index+1];
        
        if(index==-1)
        {
            return solve(index+1,offers,m,memo);
        }
        
        
        
        int l = binary_search(offers,index+1,m-1,offers[index]);
        
        return memo[index+1] = max(solve(index+1,offers,m,memo), offers[index][2] + solve(l,offers,m,memo));
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        sort(offers.begin(),offers.end());
        
        int m = offers.size();
        vector<int>memo(m+1,-1);
       return solve(-1,offers,m,memo);
        
       
    }
};
