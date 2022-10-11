class Solution {
public:
    
    vector<int>res;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(nums[i]);
        }
        
    }
    
    int pick(int target) {
        
        
        vector<int>temp;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]==target)
            {
                 temp.push_back(i);
            }
        }
        
      
        int answer_index =  (int)(((float)rand()/RAND_MAX)*temp.size());
        
        
        return temp[answer_index];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
