class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int curOdd = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int result=0;
        for(auto num : nums){
            if(num%2){
                curOdd++;
            }

            if(mp.find(curOdd-k)!=mp.end()){
                result += mp[curOdd-k];
            }
            mp[curOdd]++;
        }

        return result;
    }
};
