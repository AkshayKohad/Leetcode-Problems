class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)return -1;
        if(n==2)return 0;
        
        
        int cnt = 1;
        int dominant = nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(dominant==nums[i])
                cnt++;
            
            else{
                cnt--;
                if(cnt==0)
                {
                    dominant = nums[i];
                    cnt=1;
                }
            }
        }
        
        vector<int>prefix(n,0);
        
        if(nums[0]==dominant)
        {
            prefix[0] = 1;
            
        }
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==dominant)
                prefix[i]+=1;
            
            prefix[i] += prefix[i-1];
        }
        
        for(int i=0;i<n-1;i++)
        {
            int cnt = prefix[i];
            int cnt2 = prefix[n-1]-prefix[i];
            
            if(cnt*2 > i+1  && cnt2*2 > n-i-1)
                return i;
        }
        return -1;
        
    }
};
