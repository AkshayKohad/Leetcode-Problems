class Solution {
public:
    

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        vector<long long>prefix_sum(n);
        prefix_sum[0] = nums[0];
        
        
        for(int i=1;i<n;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }
        
        vector<long long>answer;
        
        for(int i=0;i<queries.size();i++)
        {
            long long  val = queries[i];
            
            long long index = upper_bound(nums.begin(),nums.end(),val) - nums.begin();
            
            long long leftSum = 0;
            if(index>0)
                leftSum = prefix_sum[index-1];
            
            long long rightSum = prefix_sum[n-1]-leftSum;
            
            
            
            
            
            answer.push_back(val*index - leftSum + rightSum - (n-index)*val);
             
        
        }
        
        return answer;
    }
};
