class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>a;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
           
       if(s.find(nums[i])!=s.end())
           continue;
            int sum = nums[i];
            s.insert(nums[i]);
            sum = sum*(-1);
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                vector<int>b;
                if(nums[j-1]==nums[j] && j-1!=i)
                {
                    j++;
                    continue;
                }
                
                if(nums[j]+nums[k]==sum)
                {
                   
                    
                    a.push_back({nums[i],nums[j],nums[k]});
                   
                    j++;
                    k--;
                    
                }
                
                else if(nums[j]+nums[k]>sum)
                    k--;
                else if(nums[j]+nums[k]<sum)
                    j++;
                
            }
        }
        
        return a;
    }
};
