class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)
            return;
        
        bool flag = false;
        int n = nums.size();
        
        int val = nums[n-1];
        int index;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<val)
            {
                index = i;
                flag = true;
                break;
            }
            
            else{
                val = nums[i];
            }
        }
        
        
        if(flag==false)
        {
            reverse(nums.begin(),nums.end());
                return;
        }
        
        
        val = nums[index];
        //cout<<val<<endl;
        for(int i=n-1;i>index;i--)
        {
            if(val<nums[i])
            {
                swap(nums[index],nums[i]);
                break;
            }
        }
        
        reverse(nums.begin()+index+1,nums.end());
        
        return;
        
    }
};
