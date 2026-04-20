class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        vector<int>prefix_1(n+1,0);
        vector<int>prefix_0(n+1,0);
        for(int i=0;i<n;i++){
            prefix_1[i+1] += prefix_1[i] + (s[i] == '0' ? 0 : 1);
            prefix_0[i+1] += prefix_0[i] + (s[i] == '0' ? 1 : 0);
        }
        int result = 0;
        unordered_map<int,vector<int>>mp;
        mp[0].push_back(0);
        int cur_sum = 0;
        for(int i=0;i<n;i++){
            cur_sum += (s[i] == '0' ? -1 : 1);

            if(mp.find(cur_sum) != mp.end()){
                result = max(result, i+1-mp[cur_sum][0]);
            }

            if(mp[cur_sum].size()<2)
                mp[cur_sum].push_back(i+1);

            if(mp.find(cur_sum-2) != mp.end()){

                int sz = mp[cur_sum-2].size();

                int ind = mp[cur_sum-2][0];
                int pref_val = prefix_0[ind];
                int pref_val2 = prefix_0[n]-prefix_0[i+1];
                if(pref_val>0 || pref_val2>0){
                    result = max(result,i+1-ind);
                }else{
                    if(sz>1){
                        ind = mp[cur_sum-2][1];
                        result = max(result,i+1-ind);
                    }
                }
            }

            if(mp.find(cur_sum+2) != mp.end()){

                int sz = mp[cur_sum+2].size();

                int ind = mp[cur_sum+2][0];
                int pref_val = prefix_1[ind];
                int pref_val2 = prefix_1[n]-prefix_1[i+1];
                if(pref_val>0 || pref_val2>0){
                    result = max(result,i+1-ind);
                }else{
                    if(sz>1){
                        ind = mp[cur_sum+2][1];
                        result = max(result,i+1-ind);
                    }
                }
            }                
        }

        return result;
    }
};
