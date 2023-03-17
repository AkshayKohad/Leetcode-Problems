class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int>numbers_smaller_pivot;
        vector<int>numbers_larger_pivot;
        vector<int>numbers_equal_pivot;

        // numbers smaller than pivot

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
              numbers_smaller_pivot.push_back(nums[i]);
            }

            else if(nums[i]==pivot)
            {
              numbers_equal_pivot.push_back(nums[i]);
            }

            else if(nums[i]>pivot)
            {
              numbers_larger_pivot.push_back(nums[i]);
            }
        }

        vector<int>result;
        result.insert(result.end(),numbers_smaller_pivot.begin(),numbers_smaller_pivot.end());
        result.insert(result.end(),numbers_equal_pivot.begin(),numbers_equal_pivot.end());
        result.insert(result.end(),numbers_larger_pivot.begin(),numbers_larger_pivot.end());
        return result;
    }
};
