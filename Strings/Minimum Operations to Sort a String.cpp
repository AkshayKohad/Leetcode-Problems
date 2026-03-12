class Solution {
public:
    int minOperations(string s) {
        string k = s;
        int n = s.length();
        sort(k.begin(),k.end());

        if(k==s)return 0;

        if(n==2)return -1;

        if(k[0]==s[0] || k[n-1]==s[n-1])return 1;

        string temp = s;
        sort(s.begin(),s.begin()+n-1);
        sort(s.begin()+1,s.end());

        sort(temp.begin()+1,temp.end());
        sort(temp.begin(),temp.begin()+n-1);

        if(k == s || temp == k)return 2;

        return 3;
    }
};
