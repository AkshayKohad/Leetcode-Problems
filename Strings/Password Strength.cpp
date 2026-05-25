class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char>char_set;
        for(auto pass : password){
            char_set.insert(pass);
        }
        int result = 0;
        for(auto ch_st : char_set){
            if(ch_st >= 'a' && ch_st <= 'z')result += 1;
            else if(ch_st >= 'A' && ch_st <= 'Z')result += 2;
            else if(ch_st >= '0' && ch_st <= '9')result += 3;
            else if(ch_st == '!' || ch_st == '@' || ch_st == '#' || ch_st == '$')result += 5;
        }

        return result;
    }
};
