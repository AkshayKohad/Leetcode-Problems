class Solution {
public:
    
    
 bool check(string a,string b)
  {
      for(int i=0;i<=a.size()-b.size();i++)
      {
          
         // cout<<b<<" "<<a.substr(i,b.size())<<endl;
          if(b==a.substr(i,b.size()))
          return true;
          
      }
      
      return false;
  }
    
    int repeatedStringMatch(string a, string b) {
        // code here
        string strA = a;
          int repeat = b.length()/a.length();
        
        int count = 1;
        
        for(int i=0;i<repeat+2;i++)
        {
            if(a.length()>=b.length() && check(a,b))
                return count;
            
            a += strA;
            count++;
        }
        
        return -1;
    }
};
