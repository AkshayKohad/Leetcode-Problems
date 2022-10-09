class Solution {
public:
    
    bool check(string s,unordered_map<char,int>&mp)
    {
        
        
        unordered_map<char,int>t;
        for(int j=0;j<s.length();j++)
        {
            t[s[j]]++;
        }
        
        for(auto k:t)
        {
            if(mp[k.first] < k.second)
                return false;
        }
        
        return true;
    }
    
    void add(string s,unordered_map<char,int>&mp,int&ans,vector<int>&score)
    {
        
        
        for(int j=0;j<s.length();j++)
        {
            mp[s[j]]--;
            
//             int k = s[j] - 'a';
            
//             ans += score[k];
        }
        
        
    }
    
    
    void remove(string s,unordered_map<char,int>&mp,int&ans,vector<int>&score)
    {
        
        
        for(int j=0;j<s.length();j++)
        {
            mp[s[j]]++;
            
//             int k = s[j] - 'a';
            
//             ans -= score[k];
        }
        
        
    }
    
    
    int findscore(vector<int>&score,string s)
    {
        int cunt=0;
        for(auto it:s)
        {
            cunt+=score[it-'a'];
        }
        return cunt;
    }

    
    void solve(vector<string>& words, unordered_map<char,int>&mp, vector<int>& score,int &res,int ans,int count)
    {
        if(count==words.size())
        {
            
            res = max(res,ans);
            
            return;
        }
        
        
            if(check(words[count],mp))
            {
              add(words[count],mp,ans,score);
                int temp = findscore(score,words[count]);
                 // res = max(ans,res);
                 solve(words,mp,score,res,ans+temp,count+1);
               
              remove(words[count],mp,ans,score);  
            }
        
        solve(words,mp,score,res,ans,count+1);
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<letters.size();i++)
        {
            mp[letters[i]]++;
        }
        
        int n = words.size();
        vector<int>visited(n,0);
        int res = 0;
        int ans = 0;
        solve(words,mp,score,res,ans,0);
        
        
        return res;
    }
};

