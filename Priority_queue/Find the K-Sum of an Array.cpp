class Solution {
public:
    
    
    long long kSum(vector<int>& nums, int k) {
     
        
        int n = nums.size();
        long long  total = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0) total += nums[i];
            
            else
                nums[i] *= -1;
        }
        
        vector<long long >top_k = {0};
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>nxt_greater;
        
        sort(nums.begin(),nums.end());
        
        nxt_greater.push({nums[0],1});
        
        
        
        while(top_k.size()<k)
        {
           pair<long long,long long>cur = nxt_greater.top();
            nxt_greater.pop();
            
            top_k.push_back(cur.first);
            
            long long val = cur.first;
            long long index = cur.second;
            
            
            if(index<n)
            {
                nxt_greater.push({val - nums[index-1] + nums[index],index+1});
                
                nxt_greater.push({val + nums[index],index+1});
            }
        }
        
        return total - top_k[k-1];
    }
};
