class Solution {
public:
    int solve_1_char(string &s,int &n){
        int result = 0;
        int i=0;
        int j=0;
        while(j<n){
            int cnt = 0;
            j=i;
            while(j<n && s[i]==s[j]){
                cnt++;
                j++;
            }
            result = max(result,cnt);
            i=j;
        }
        return result;
    }

    int solve_2_char(string &s,int &n,char a,char b){
        int i=0;
        int j=0;
        int result = 0;
        while(i<n){
            while(i<n && s[i]!=a && s[i]!=b)i++;
            unordered_map<int,int>mp;
            mp[0] = i-1;
            int diff = 0;
            while(i<n && s[i]==a || s[i]==b){
                diff += (s[i] == a ? 1:-1);
                if(mp.count(diff))result = max(result,i-mp[diff]);
                else mp[diff] = i;
                i++;
            }   
        }
        return result;
    }

    int solve_3_char(string &s, int &n){
        int result = 0;
        map<pair<int,int>,int>mp;
        mp[{0,0}] = -1;
        vector<int>cnt(3,0);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
            int x = cnt[0]-cnt[1];
            int y = cnt[1]-cnt[2];
            if(mp.count({x,y}))result = max(result,i-mp[{x,y}]);
            else mp[{x,y}] = i;
        }

        return result;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int x = solve_1_char(s,n);
        int y = max({solve_2_char(s,n,'a','b'),solve_2_char(s,n,'a','c'),solve_2_char(s,n,'b','c')});
        int z = solve_3_char(s,n);
        return max({x,y,z});
    }
};
