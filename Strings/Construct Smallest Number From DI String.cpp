class Solution {
public:
    
    
    bool check(string t,string p)
    {
        for(int i=1;i<t.size();i++)
        {
            if(t[i]>t[i-1] && p[i-1]!='I')
                return false;
            
            else if(t[i]<t[i-1] && p[i-1]!='D')
                return false;
        }
        
        
        return true;
    }
    
    string smallestNumber(string pattern) {
        
        
        string t;
        
        int n = pattern.size();
        
        
        for(int i=1;i<=n+1;i++)
        {
             t += to_string(i);
        }
        
        
        string res = "";
        do{
            
            if(check(t,pattern))
            {
                if(res.size()==0)
                    res = t;
                
                else{
                    res = min(res,t);
                }
            }
            
        }while(next_permutation(t.begin(),t.end()));
        
        
        return res;
    }
};
