class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long>char_cost(26,0);
        long long total_cost = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            int ch = s[i]-'a';
            char_cost[ch] += cost[i];
            total_cost += cost[i];
        }
        long long result = LLONG_MAX;
        for(int i=0;i<26;i++){
            result = min(result,total_cost-char_cost[i]);
        }

        return result;
    }
};
