class Solution {
public:
    
    void merge(vector<int>& nums,int low,int mid,int high,int &count)
{
    vector<int>c;
    
    int i = low;
    int j = mid+1;
    
    while(i<=mid && j<=high)
    {
        if(nums[i]<=nums[j])
        {
            c.push_back(nums[i]);
            i++;
        }
        
        else{
            c.push_back(nums[j]);
            j++;
            //count += (mid-i+1);
        }
    }
    
    while(i<=mid)
    {
        c.push_back(nums[i]);
            i++;
    }
    
    while(j<=high)
    {
        c.push_back(nums[j]);
            j++;
    }
        
        vector<long long int>temp;
        
    for(int k = mid+1;k<=high;k++)
    {
        long long int curr = nums[k];
        temp.push_back(curr*2);
    }
       
        
     i = low;
     j = 0;
        
   while(i<=mid && j<temp.size())
    {
        if(nums[i]<=temp[j])
        {

            i++;
        }
        
        else{
            
            j++;
            count += (mid-i+1);
        }
    }
        
        
    int l = 0;
    for(int k = low;k<=high;k++)
    {
        nums[k] = c[l];
        l++;
    }
}

void mergesort(vector<int>& nums,int low,int high,int &count)
{
    if(low<high)
    {
        int mid  = (low+high)/2;
        
        mergesort(nums,low,mid,count);
        mergesort(nums,mid+1,high,count);
        merge(nums,low,mid,high,count);
    }
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
         int count = 0;
    mergesort(nums,0,n-1,count);
        
      return count;
        
        
    }
};
