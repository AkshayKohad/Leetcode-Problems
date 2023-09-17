#define ll long long

class Solution {
public:
    
    bool check(int &n,ll mid,int budget,vector<int>&composition,vector<int>&stock,vector<int>&cost)
    {
        for(int i=0;i<n;i++)
        {
            ll total_req = max((ll)(mid*composition[i] - stock[i]),(ll)0);
            
            if(budget<total_req*cost[i])
            {
                return false;
        
            }
            budget-=total_req*cost[i];
        }
        return true;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
  
        ll result = 0;
        for(int i=0;i<k;i++)
        {
            ll l=0;
            ll r = 1000000000;
            ll ans = -1;
            while(l<=r)
            {
                ll mid = (l+r)/2;
                
                if(check(n,mid,budget,composition[i],stock,cost))
                {
                    ans = mid;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            
            result = max(result,ans);
        }
        
        return result;
    }
};
