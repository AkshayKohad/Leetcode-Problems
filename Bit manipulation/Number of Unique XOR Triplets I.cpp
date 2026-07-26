class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return n;

        int result = 0;
        for(auto num : nums){
            result = result | num;
        }
        return result+1;
    }
};

