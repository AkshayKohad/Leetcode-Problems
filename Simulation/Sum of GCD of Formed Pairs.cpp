class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);

        int maxi = -1;

        for(int i=0;i<n;i++){
            maxi = max(nums[i],maxi);
            result[i] = __gcd(maxi,nums[i]);
        }

        sort(result.begin(),result.end());

        int i=0;
        int j=n-1;
        long long ans = 0;
        while(i<j){
            ans += __gcd(result[i],result[j]);
            i++;
            j--;
        }

        return ans;
    }
};
