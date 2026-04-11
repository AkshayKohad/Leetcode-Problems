class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int result = INT_MAX;
        for(auto res : mp){
            vector<int>val = res.second;
            int sz = val.size();
            if(sz<=2)continue;
            int first = val[0];
            int second = val[1];
            int third = val[2];

            int ans = abs(first-second) + abs(second-third) + abs(third-first);
            result = min(result,ans);
            int ind = 3;
            for(int j=ind;j<sz;j++){
                int temp = third;
                third = val[j];
                int temp2 = second;
                second = temp;
                first = temp2;

                ans = abs(first-second) + abs(second-third) + abs(third-first);
                result = min(result,ans);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
