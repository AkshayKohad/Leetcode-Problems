class Solution {
public:
    #define mod 1000000007
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(auto query : queries){
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            while(l<=r){
                nums[l] = ((long long)nums[l]*v)%mod;
                l = l+k;
            }
        }

        int result = 0;
        for(auto num : nums){
            result = result ^ num;
        }

        return result;
    }
};
