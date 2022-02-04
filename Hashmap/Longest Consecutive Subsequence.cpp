class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        set<int>s;
   
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
         
        }
        
      
        vector<int>b;
        for(auto it : s)
        {
         b.push_back(it);
        }
        
       
          int count=1;
        int max_count=1;
        int curr = b[0];
        
        for(int i=1;i<b.size();i++)
        {
            if(curr+1==b[i])
            {
                count++;
            }
            else
            {
                max_count = max(max_count,count);
                
                count=1;
            }
            curr = b[i];
        }
        
        max_count = max(max_count,count);
        return max_count;
    }
};
