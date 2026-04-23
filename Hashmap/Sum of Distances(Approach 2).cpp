class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>result(n,0);

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto val : mp){
            vector<int>cur = val.second;
            int cur_val = val.first;

            if(cur.size()==1){
                result[cur[0]] = 0;
                continue;
            }

            long long prefix_sum = 0;
            for(int i=0;i<cur.size();i++){
                prefix_sum += cur[i];
            }

            long long cur_sum = 0;
            for(int i=0;i<cur.size();i++){
                cur_sum += cur[i];

                long long res_sum = (long long)(i+1)*cur[i] - (long long)cur_sum;
                res_sum += prefix_sum - cur_sum - (cur.size()-1-i)*cur[i]; 

                result[cur[i]] = res_sum;
            }

        }

        return result;
    }
};
