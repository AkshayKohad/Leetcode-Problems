class Solution {
public:
    
    void solution(string a, vector<string>&b,int count,int count1,int n)
    {
        if(count==n)
        {
            while(count1!=n)
            {
                a.push_back(')');
                count1++;
            }
            
            b.push_back(a);
            return;
        }
        
        if(count==count1)
        {
            a.push_back('(');
            solution(a,b,count+1,count1,n);
            a.pop_back();
        }
        
        else if(count>count1)
        {
            a.push_back('(');
            solution(a,b,count+1,count1,n);
            a.pop_back();
            
            a.push_back(')');
            solution(a,b,count,count1+1,n);
            a.pop_back();
            
        }
        else 
        {
            return;
        }
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        
        int count=0,count1=0;
        string a;
        vector<string>b;
        
        solution(a,b,count,count1,n);
            return b;
    }
};
