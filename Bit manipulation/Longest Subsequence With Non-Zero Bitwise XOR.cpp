class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int>bit_cnt(32,0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=31;j>=0;j--){
                int bit = (nums[i]>>j)&1;
                bit_cnt[j]+=bit;
            }
        }

        int res = 0;
        for(int i=31;i>=0;i--){
            if(bit_cnt[i]==0)continue;
            if(bit_cnt[i]%2){
                return n;
            }else{
                res = n-1;
            }
        }

        return res;
    }
};
// 2 4 5 5
