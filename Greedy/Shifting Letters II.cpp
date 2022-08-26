class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
    // return s;
        int n = s.length();
        vector<int>sh(n+1,0);
        
        for(int i=0;i<shifts.size();i++)
        {
            int x = shifts[i][0];
            int y = shifts[i][1];
            int status = shifts[i][2];
            
            
            //backward
            if(status==0)
            {
                
                sh[x]--;
                sh[y+1]++;
                
            }
            
            //forward
            else{
               
                sh[x]++;
                sh[y+1]--;
            }
            
            
            
        }
        
        
        for(int i=1;i<=n;i++)
        {
            sh[i] += sh[i-1];
        }
        
        for(int i=0;i<n;i++)
        {
            if(sh[i]<0)
            {
               int  curr_val = s[i]-'a';
                
                curr_val += sh[i];
                
               if(curr_val<0)
               {
                int div = abs(curr_val)/26;
                   div++;
                   
                   curr_val += div*26;
               }
                
                curr_val = curr_val%26;
                
                char ch = curr_val + 'a';
                
                
                s[i] = ch;
            }
            
            else if(sh[i]==0)
                continue;
            
            else{
                int curr_val = s[i]-'a';
                
                curr_val += sh[i];
                
                curr_val = curr_val%26;
                
               
                char ch = curr_val + 'a';
                
                s[i] = ch;
            }
        }
        
        
        return s;
    }
};
