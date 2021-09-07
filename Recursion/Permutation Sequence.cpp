class Solution {
public:
    void solution(string s,int n,int &k,string &a,vector<bool>&visited,int &flag)
    {
        if(a.length()==n)
        {
            k--;
            if(k==0)
            {
                flag=1;
                return;
            }
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                a = a + s[i];
                solution(s,n,k,a,visited,flag);
                if(flag==1)
                    return;
                visited[i]=false;
                a.erase(a.end()-1);
            }
        }
    }
    string getPermutation(int n, int k) {
        string s;
        if(n==1)
            s="1";
        else if(n==2)
            s="12";
        else if(n==3)
            s="123";
        else if(n==4)
            s="1234";
        else if(n==5)
            s="12345";
        else if(n==6)
            s="123456";
        else if(n==7)
            s="1234567";
        else if(n==8)
            s="12345678";
        else if(n==9)
            s="123456789";
        
        vector<bool>visited(n,false);
        
        string a;
        
        int flag = 0;
        solution(s,n,k,a,visited,flag);
        
        return a;
    }
};
