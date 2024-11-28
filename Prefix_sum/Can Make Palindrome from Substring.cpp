class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<vector<int>>prefix_char_frequency(n+1,vector<int>(26,0));

        vector<int>prefix_char(26,0);
        prefix_char_frequency[0] = prefix_char;

        for(int i=1;i<=n;i++){
            int ch = s[i-1]-'a';
            prefix_char[ch]++;
            prefix_char_frequency[i] = prefix_char;
        }

        vector<bool>result;
        for(auto query : queries){
            int l = query[0];
            int r = query[1];
            int k = query[2];

            vector<int>temp_prefix(26,0);
            int cnt_even = 0;
            int cnt_odd = 0;
            for(int i=0;i<26;i++){
                int cur_count = prefix_char_frequency[r+1][i] - prefix_char_frequency[l][i];
                if(cur_count%2){
                    cnt_odd++;
                }else{
                    cnt_even++;
                }
            }
           
            if(cnt_odd>1){
                if(2*k>=cnt_odd-1){
                    result.push_back(true);
                }else{
                    result.push_back(false);
                }
            }else{
                result.push_back(true);
            }
        }

        return result;
    }
};
