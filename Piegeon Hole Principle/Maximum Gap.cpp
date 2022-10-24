class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<2)
            return 0;
        
        if(n==2)
        {
            return abs(nums[0]-nums[1]);
        }
        
        
        int mini = nums[0];
        int maxi = 0;
        
        
        for(int i=0;i<n;i++)
        {
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        
//         if(maxi == mini)
//             return 0;
        
        int interval = ceil((double)(maxi-mini)/(n-1));
        
        vector<int>min_bucket(n-1,INT_MAX);
        vector<int>max_bucket(n-1,-1);
        
        
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]==mini || nums[i]==maxi) continue;
            
            
            int bucket_index = (nums[i]-mini)/interval;
            
            min_bucket[bucket_index] = min(min_bucket[bucket_index],nums[i]);
            
            max_bucket[bucket_index] = max(max_bucket[bucket_index],nums[i]);
            
        }
        
        int res_max = 0;
        int prev = mini;
        //int i=0;
        //int j=1;
        
        for(int i=0;i<n-1;i++)
        {
            if(min_bucket[i]!=INT_MAX)
            {
            res_max = max(res_max,min_bucket[i]-prev);
            prev = max_bucket[i];
            }
        }
        
        res_max = max(maxi-prev,res_max);
        
        return res_max;
        
    }
};
