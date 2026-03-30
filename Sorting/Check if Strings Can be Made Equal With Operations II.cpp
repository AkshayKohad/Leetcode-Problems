class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1_even,s1_odd,s2_even,s2_odd;

        int n = s1.length();

        for(int i=0;i<n;i++){
            if(i%2==0){
                s1_even.push_back(s1[i]);
                s2_even.push_back(s2[i]);
            }else{
                s1_odd.push_back(s1[i]);
                s2_odd.push_back(s2[i]);
            }
        }

        sort(s1_even.begin(),s1_even.end());
        sort(s2_even.begin(),s2_even.end());
        sort(s1_odd.begin(),s1_odd.end());
        sort(s2_odd.begin(),s2_odd.end());
        
        if(s1_even == s2_even && s1_odd == s2_odd)return true;

        return false;
    }
};


