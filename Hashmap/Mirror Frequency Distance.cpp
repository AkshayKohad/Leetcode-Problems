class Solution {
public:
    int mirrorFrequency(string s) {
        vector<char>mirror_char(26);
        vector<char>mirror_digit(10);
        int i=0;
        for(char ch = 'z';ch>='a';ch--,i++){
            mirror_char[i] = ch;
        }
        i=0;
        for(char ch = '9';ch>='0';ch--,i++){
            mirror_digit[i] = ch;
        }

        unordered_map<char,int>mp;
        for(auto ch : s){
            mp[ch]++;
        }
        int result = 0;
        for(auto ch : s){
            if(mp.find(ch)==mp.end())continue;
            int freq_c = mp[ch];
            int freq_m;
            if(ch>='a' && ch<='z'){
                freq_m = mp[mirror_char[ch-'a']];
                mp.erase(ch);
                mp.erase(mirror_char[ch-'a']);
            }else{
                freq_m = mp[mirror_digit[ch-'0']];
                mp.erase(ch);
                mp.erase(mirror_digit[ch-'0']);
            }
            result += abs(freq_c-freq_m);
        }
        return result;
    }
};
