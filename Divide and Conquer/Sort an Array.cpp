class Solution {
public:
    
    void merge(int start,int mid,int end,vector<int>&nums)
    {
         int i = start;
         int j = mid+1;
        
        vector<int>a;
        
        while(i<=mid && j<=end)
        {
            if(nums[i]<=nums[j])
            {
                a.push_back(nums[i]);
                i++;
            }
            
            else{
                a.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=mid)
        {
            a.push_back(nums[i]);
            i++;
        }
        
        while(j<=end)
        {
            a.push_back(nums[j]);
            j++;
        }
        
        int l = start;
        
        for(int i=0;i<a.size();i++)
        {
            nums[l] = a[i];
            l++;
        }
    }
    
    void mergeSort(int start,int end,vector<int>&nums)
    {
        if(start<end)
        {
            int mid = (start+end)/2;
            
            mergeSort(start,mid,nums);
            
            mergeSort(mid+1,end,nums);
            
            merge(start,mid,end,nums);
        }
            
    }
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        
        mergeSort(0,n-1,nums);
        return nums;
        
    }
};
