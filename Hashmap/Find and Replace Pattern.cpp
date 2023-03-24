class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        

        vector<string>result;
        for(int i=0;i<words.size();i++)
        {
            unordered_map<char,char>mp;
            unordered_set<char>s;
             bool flag = true;
            for(int j=0;j<words[i].size();j++)
            {
                if(mp.find(pattern[j])!=mp.end())
                {
                    if(mp[pattern[j]]!=words[i][j])
                    {
                        flag=false;
                        break;
                    }
                }
                else{
                    if(s.find(words[i][j])==s.end())
                    {
                    mp[pattern[j]] = words[i][j];
                    s.insert(words[i][j]);
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
            }

            if(flag==true)
            {
               result.push_back(words[i]);
            }
        }

        return result;
    }
};
