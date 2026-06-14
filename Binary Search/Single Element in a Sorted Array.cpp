class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
    if(n==1)return nums[0];
    // Replace this placeholder return statement with your code
    int l = 0;
    int r = n-1;
    
    while(l<=r){
        int mid = (r-l)/2 + l;
        
        if(mid == 0){
            if(nums[mid]!=nums[mid+1])return nums[mid];
            else l = mid+1;
        }else if(mid == n-1){
            if(nums[mid]!=nums[mid-1])return nums[mid];
            else r = mid-1;
        }else{
            if(nums[mid] == nums[mid+1]){
                if(mid%2 == 1)r = mid-1;
                else l = mid+1;
            }else if(nums[mid] == nums[mid-1]){
                if(mid%2 == 1)l = mid+1;
                else r = mid-1;
            }else{
                return nums[mid];
            }
        }
    }
    return -1;
    }
};
