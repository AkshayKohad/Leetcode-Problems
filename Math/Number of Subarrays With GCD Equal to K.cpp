class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res=0;
        for(int i=0;i<size(nums);++i)
            for(int j=i;j<size(nums)&&nums[j]%k==0;++j){
                nums[i]=__gcd(nums[i],nums[j]);
                res+=nums[i]==k;
            }
        return res;
    }
};
