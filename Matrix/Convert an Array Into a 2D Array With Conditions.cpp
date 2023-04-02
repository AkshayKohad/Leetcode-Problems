class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        vector<vector<int>>result;
        
        int size = mp.size();
        int count_erase = 0;
        
        while(count_erase<size)
        {
            vector<int>temp;
            
          for(auto k:mp)
          {
              
              if(k.second==0)
                  continue;
                  
              temp.push_back(k.first);
              
             mp[k.first]--;
              
               if(mp[k.first]==0)
               {
                   count_erase++;
               }
          }
            result.push_back(temp);
            
           
            
            
        }
        
        return result;
        
    }
};
