class Solution {
public:
    int longestContinuousSubstring(string s) {
        unordered_map<char,int>mp;
        
        int n = s.length();
        
        int i=0;
        int j=1;
        
        mp[s[i]] = i;
        
        int res = 1;
        while(j<n)
        {
            if(s[j]=='a')
            {
                i=j;
                mp[s[j]] = j;
                j++;
               // continue;
            }
            
            else{
            int ch = s[j] - 'a';
            
            ch = ch-1;
            
            char chr = ch + 'a';
            
                
                if(mp.find(chr)==mp.end())
                {
                     i=j;
                   mp[s[j]] = j;
                    j++;
                }
                
                else{
                    int index = mp[chr];
                    
                    if(index+1==j)
                    {
                        res = max(res,j-i+1);
                        mp[s[j]] = j;
                        j++;
                            
                    }
                    
                    else{
                        i=j;
                        mp[s[j]] = j;
                        j++;
                    }
                }
            }
            
            
            
        }
        
        return res;
    }
};
