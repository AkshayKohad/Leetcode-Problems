class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int>mp;

        for(auto word : words){
            if(word.length()<k)continue;

            string new_word = word.substr(0,k);
            mp[new_word]++;
        }
        int result = 0;
        for(auto val : mp){
            if(val.second >=2){
                result++;
            }
        }
        return result;
    }
};
