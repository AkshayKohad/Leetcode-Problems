class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int l = 0;
        
        int n = nums.size();
        
        int mid = n/2;
        
        int count = 0;
        while(l<n/2 && mid<n)
        {
            if(2*nums[l]<=nums[mid])
            {
                count = count+2;
                l++;
                mid++;
            }
            
            else{
                mid++;
            }
            
        }
        
        return count;
    }
};
