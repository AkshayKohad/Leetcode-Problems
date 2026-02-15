class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>val;
        unordered_map<int,int>res_mp;
        for(auto num : nums){
            if(mp.find(num)==mp.end()){
                val.push_back(num);
                mp[num] = 1;
            }else{
                mp[num]++;
            }
        }

        for(auto u : mp){
            res_mp[u.second]++;
        }
        int n = val.size();
        int i=0;
        int first_result = -1;
        int cnt_result = 0;
        unordered_set<int>st;
        while(i<n){
            int cnt = mp[val[i]];
            if(res_mp[cnt]>1){
                i++;
                continue;
            }
            else return val[i];
            
            i++;
        }

        return -1;
    }
};
