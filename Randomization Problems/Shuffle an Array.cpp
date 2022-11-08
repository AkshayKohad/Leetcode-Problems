class Solution {
public:
    vector<int>original;
   // vector<int>use;
     
    int n;
    Solution(vector<int>& nums) {
         n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            original.push_back(nums[i]);
            //use.push_back(nums[i]);
        }
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        
        vector<int>res = original;
        for(int i=0;i<n;i++)
        {
            int val_index = rand()%n;
            
           swap(res[i],res[val_index]);            
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
