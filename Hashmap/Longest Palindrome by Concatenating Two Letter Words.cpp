class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
         map<string,int>s;
        int flag_occurence_self_palindrome_string = false;
        
        int count = 0;
        for(int i=0;i<words.size();i++)
        {
            string cur = words[i];
            string rev_cur = cur;
            reverse(rev_cur.begin(),rev_cur.end());
            
            
            
                if(s.find(rev_cur)!=s.end())
                {
                    count += 4;
                    
                    s[rev_cur]--;
                    
                    if(s[rev_cur]==0)   
                    {
                        s.erase(rev_cur);
                    }
                }
                
                else{
                    s[cur]++;
                }
            
        }
        
        for(auto w:s)
        {
            string t = w.first;
            
            if(t[0]==t[1])
            {
                flag_occurence_self_palindrome_string = true;
            }
        }
        
        if(flag_occurence_self_palindrome_string)
        {
            count += 2;
        }
        
        return count;
    }
};
