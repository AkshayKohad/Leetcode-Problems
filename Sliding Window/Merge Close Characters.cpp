class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<int>char_position(26,-1);
        string ans;
        int deleted_char = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            int ch = s[i]-'a';
            if(char_position[ch]==-1){
                char_position[ch] = i-deleted_char;
                ans.push_back(s[i]);
            }else{
                int diff = i-deleted_char-char_position[ch];

                if(diff<=k){
                    deleted_char++;
                }else{
                    ans.push_back(s[i]);
                    char_position[ch] = i-deleted_char;
                }
                
            } 
        }

        return ans;
    }
};
