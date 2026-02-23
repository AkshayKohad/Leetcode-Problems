class Solution {
public:
    string maximumXor(string s, string t) {
        int cnt_1 = 0;
        int cnt_0 = 0;
        for(auto ch : t){
            if(ch == '0')cnt_0++;
            else cnt_1++;
        }

        string result;
        for(auto ch : s){
            if(ch == '0'){
                if(cnt_1 > 0){
                    result.push_back('1');
                    cnt_1--;
                }else{
                    result.push_back('0');
                    cnt_0--;
                }
            }else{
                if(cnt_0 > 0){
                    result.push_back('1');
                    cnt_0--;
                }else{
                    result.push_back('0');
                    cnt_1--;
                }
            }
        }

        return result;
    }
};
