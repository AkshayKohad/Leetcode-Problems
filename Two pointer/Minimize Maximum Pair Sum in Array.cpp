class Solution {
public:
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());

       int n = nums.size();

       int i=0;
       int j=n-1;

     int res = INT_MIN;

       while(i<j)
       {
         res = max(res,nums[i]+nums[j]);
         i++;
         j--;
       }
       return res;
        
    }
};
