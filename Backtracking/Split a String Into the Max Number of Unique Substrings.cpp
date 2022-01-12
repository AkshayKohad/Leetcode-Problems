class Solution {
public:
    
    void solve(string s,unordered_set<string>&a,int &max,int i)
    {
        if(i==s.length())
        {
            if(max<a.size())
                max=a.size();
            
            return;
        }
        string b;
        for(int j=i;j<s.length();j++)
        {
            b.push_back(s[j]);
            
            if(a.find(b)==a.end())
            {
                a.insert(b);
                solve(s,a,max,j+1);
                a.erase(b);
            }
            
        }
        
        
    }
    int maxUniqueSplit(string s) {
        int max = 0;
        unordered_set<string>a;
        solve(s,a,max,0);
        
        return max;
    }
};
