class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
//         while(nums1.size()>m)
//         {
//             nums1.pop_back();
//         }
        
//         while(nums2.size()>n)
//         {
//             nums2.pop_back();
//         }
        
        for(int j = m;j<m+n;j++)
        {
            nums1[j] = nums2[j-m];
        }
//         cout<<nums1.size()<<endl;
//         cout<<nums2.size()<<endl;
        
        int gap = ceil((float)(m+n)/2);
        
      while(gap>1)
      {
          int i = 0;
          int j = gap;
        while(j<m+n)
        {
            
                 if(nums1[i]>nums1[j])
                    {
                        swap(nums1[i],nums1[j]);
                        
                    }
                
            
           i = i+1;
           j = j+1; 
            
        }
          gap = ceil((float)gap/2);
      }
        
        if(gap==1)
        {
         int i = 0;
          int j = gap;
        while(j<m+n)
        {
            
                 if(nums1[i]>nums1[j])
                    {
                        swap(nums1[i],nums1[j]);
                        
                    }
                
            
           i = i+1;
           j = j+1; 
            
        }   
        }
    }
};
