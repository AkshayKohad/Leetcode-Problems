class Solution {
public:
    
    static bool mycmp(vector<int>&f,vector<int>&s)
    {
        return abs(f[0]-f[1]) > abs(s[0]-s[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        sort(costs.begin(),costs.end(),mycmp);
        
        int n = costs.size();
        
        int a = n/2;
        int b = n/2;
        
        int res = 0;
        int i=0;
        while(a!=0 && b!=0)
        {
           if(costs[i][0]>costs[i][1])
           {
             b--;
             res+=costs[i][1];
           }
            
            else
            {
                a--;
                res+=costs[i][0];
            }
            i++;
        }
        
        
        while(a--)
        {
            res += costs[i][0];
            i++;
        }
        
        while(b--)
        {
            res += costs[i][1];
            i++;
        }
       
        
        return res;
    }
};

