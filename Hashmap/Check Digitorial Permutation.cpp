class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int>factorials = {1,1,2,6,24,120,720,5040,40320,362880};
        int new_digit = 0;
        unordered_map<int,int>mp;
        while(n>0){
            int rem = n%10;
            n = n/10;
            new_digit += factorials[rem];
            mp[rem]++;
        }

        while(new_digit>0){
            int rem = new_digit%10;
            if(mp.count(rem)==0)return false;
            mp[rem]--;
            if(mp[rem] == 0){
                mp.erase(rem);
            }
            new_digit = new_digit/10;
        }

        if(mp.size()==0)return true;
        return false;   
    }
};
