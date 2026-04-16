class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int result = 0;
        for(auto num : nums){
            int val = num;

            while(val>0){
                int rem = val%10;
                if(rem == digit){
                    result++;
                }
                val = val/10;
            }
        }

        return result;
    }
};
