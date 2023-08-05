class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        
        int n = nums.size();
        
        map<int,vector<int>>mp;
       
        
        for(int i=0;i<n;i++)
        {
            
            mp[nums[i]].push_back(i);            
              
        }
        
        int res = INT_MAX;
        for(auto k:mp)
        {
         
            vector<int>temp = k.second;
            
           int cnt = 0;
            
           
            for(int i=0;i<temp.size()-1;i++)
            {
                int val = temp[i+1]-temp[i]-1;
                int gap = val/2;
                int mod = val%2;
                
                if(mod!=0)
                    gap++;
                cnt = max(cnt, gap);
                
              
            }
            int val = n-1-temp[temp.size()-1] + temp[0];
            int gap = val/2;
            int mod = val%2;
            
            if(mod!=0)
                gap++;
            
            cnt = max(cnt,gap);
          
            res = min(res,cnt);
        }
        
       
        return res;
        
       
    }
    
    
};
