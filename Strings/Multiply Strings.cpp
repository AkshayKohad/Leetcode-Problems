class Solution {
public:
    string multiply(string num1, string num2) {
     
        int n = num1.size();
        int m = num2.size();
        
        
        
        string t = "";
        
        vector<string>s;
        int max_size = 0;
        for(int i=n-1;i>=0;i--)
        {
          int  borrow = 0;    
            int val1 = num1[i] - '0';
            string temp;
          for(int j=m-1;j>=0;j--)
          {
              int val2 = num2[j] - '0';
              
              int res = val1*val2 + borrow;
              
              int rem = res%10;
              
               borrow = res/10;
              
              //cout<<rem<<" ";
              temp.push_back(rem + '0');
          }
            
            //cout<<endl;
            if(borrow!=0) temp.push_back(borrow + '0');
            reverse(temp.begin(),temp.end());
            
            temp += t;
            
            if(max_size<temp.length())
                max_size = temp.length();
            
            //max_size = max(max_size,temp.length());
            s.push_back(temp);
            //cout<<temp<<endl;
            t += "0";
        }
        
        
        string res;
        
        int borrow = 0;
        for(int count=1;count<=max_size;count++)
        {
            int sum = 0;
        for(int i=0;i<s.size();i++)
        {
            int n = s[i].length();
            
            if(n-count<0) continue;
            
            int val = s[i][n-count] - '0';
            
            sum += val;
            
        }
            
            sum += borrow;
            
            int rem = sum%10;
            
            int div = sum/10;
            
            res.push_back(rem+'0');
            
            borrow = div;
            
        }
        
        if(borrow!=0) res.push_back(borrow+'0');
        
        int j = res.size()-1;
        
        //removing leading zeroes
        while(j>=1 && res[j]=='0')
        {
            res.pop_back();
            j--;
        }
        
        reverse(res.begin(),res.end());
        
        
        return res;
    }
};
