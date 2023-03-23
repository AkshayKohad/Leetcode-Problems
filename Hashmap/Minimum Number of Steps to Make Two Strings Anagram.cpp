class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<char,int>mp;

        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }

        for(int i=0;i<t.length();i++)
        {
            if(mp.find(t[i])!=mp.end() && mp[t[i]]>0)
            {
              mp[t[i]]--;
            }
            
        }

        int result = 0;

        for(auto k:mp)
        {
            result = result + k.second;
        }

        return result;
    }
};
