class Solution {
public:
    
    
    bool check(int val,int days,vector<int>&weights)
    {
        int count = 0;
        
        int sum = 0;
        
        for(int i=0;i<weights.size();i++)
        {
           if(sum + weights[i] > val)
           {
               
               if(weights[i]>val)
                   return false;
               
               sum = weights[i];
               
               count++;
               
               if(count>=days)
                   return false;
               
               
           }
            
            else{
                sum = sum + weights[i];
            }
        }
        
        return true;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        
        int l = 0;
        int r = 0;
        
        int n = weights.size();
        
        for(int i=0;i<n;i++)
        {
            r += weights[i];
        }
        
        int ans = INT_MAX;
        
        while(l<=r)
        {
          int mid = (l+r)/2;
            
            if(check(mid,days,weights))
            {
                ans = mid;
                
                r = mid-1;
            }
            
            else{
                l = mid+1;
            }
        }
        
        return ans;
    }
};
