class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        int n = s.length();
        
        if(k==1)
        {
            string t = s+s;
            
            string res = s;
            
            for(int i=0;i<=t.length()-n;i++)
            {
                  string temp = t.substr(i,n);
                   
              //  cout<<temp<<endl;
                if(res>temp)
                {
                    res = temp;
                }
            }
            
            return res;
        }
        
        sort(s.begin(),s.end());
        
        
        return s;
        
    }
};
