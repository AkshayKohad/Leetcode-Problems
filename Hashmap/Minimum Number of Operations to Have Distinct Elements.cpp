class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            if(st.find(nums[i])!=st.end()){
                mp[nums[i]] = max(mp[nums[i]],i);
            }
            st.insert(nums[i]);
        }
        int max_index = -1;
        for(auto val : mp){
            max_index = max(max_index,val.second);
        }

        if(max_index==-1)return 0;
        if(n<3)return 1;
        int result = max_index+1;
        int ans = result/3;

        ans = ans + (result%3 > 0 ? 1:0);
        return ans;
    }
};
