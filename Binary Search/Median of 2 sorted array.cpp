class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     
        //this below thing will not work if nums1.size()>0 and nums2.size()==0
        // so we will write condition that if nums1.size()>nums2.size() we call same function and
        // swap positions of both vectors
        
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        
        
        int l = 0;
        int h = n1;
        
        while(l<=h)
        {
            int cut1 = (l+h)/2;
            int cut2 = (n2+n1+1)/2 - cut1;
            
            
            int left1;
            int left2;
            
            
            if(cut1==0)
            {
                left1 = INT_MIN;
            }
            
            else
            {
                left1 = nums1[cut1-1];
            }
            
            
            
            
            if(cut2==0)
            {
                left2 = INT_MIN;
            }
            
            else{
                left2 = nums2[cut2-1];
            }
            
            int right1 = cut1==n1 ? INT_MAX : nums1[cut1];
            
            int right2 = cut2==n2 ? INT_MAX : nums2[cut2];
            
            
            if(left1<=right2 && left2<=right1)
            {
                if((n1+n2)%2==0)
                {
                    return ( max(left1,left2) +  min(right1,right2))/2.0;
                }
                
                else{
                   return  max(left1,left2); 
                }
            }
            
            else if(left1>right2)
            {
                h = cut1 - 1;
            }
            
            else if(left2>right1)
            {
                l = cut1 + 1;
            }
        }
        
        
        return 0.0;
        
    }
};
