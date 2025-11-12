class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n = nums.size(); 
       int gcd = 0;
       int cnt_1 = 0;
       for(int i=0;i<n;i++){
        gcd = __gcd(nums[i],gcd);
        if(nums[i]==1)cnt_1++;
       }

       if(gcd > 1)return -1;

       if(cnt_1>0)return n-cnt_1;

       int min_len = n;

       for(int i=0;i<n;i++){
        int gcd_val = 0;
        for(int j=i;j<n;j++){
            gcd_val = __gcd(gcd_val,nums[j]);

            if(gcd_val == 1){
                min_len = min(min_len,j-i+1);
            }
        }

       }

       return n+min_len-2;
    }
};
