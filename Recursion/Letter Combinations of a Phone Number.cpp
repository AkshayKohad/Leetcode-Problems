class Solution {
public:
    
    void solution(vector<string> &b,vector<string> &a,string &c,int i)
    {
        if(i==b.size())
        {
            a.push_back(c);
            return;
        }
        
        for(int j=0;j<b[i].length();j++)
        {
            c = c + b[i][j];
            solution(b,a,c,i+1);
            c.erase(c.end()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>a;
        if(digits.length()==0)
            return a;
        vector<string>b;
       
        string c;
        for(int i=0;i<digits.size();i++)
        {
            if(digits[i]=='2')
            b.push_back("abc");
            
            else if(digits[i]=='3')
                b.push_back("def");
            
             else if(digits[i]=='4')
                b.push_back("ghi");
            
             else if(digits[i]=='5')
                b.push_back("jkl");
            
             else if(digits[i]=='6')
                b.push_back("mno");
            
             else if(digits[i]=='7')
                b.push_back("pqrs");
            
             else if(digits[i]=='8')
                b.push_back("tuv");
            
             else if(digits[i]=='9')
                b.push_back("wxyz");
            
        }
        
        solution(b,a,c,0);
        
        return a;
    }
};
