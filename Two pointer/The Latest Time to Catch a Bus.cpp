class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int cap)
    {
        int n=b.size(),m=p.size();
        sort(b.begin(),b.end());
        sort(p.begin(),p.end());
        int j=0,ans,prev=-1;
        for(int i=0;i<n;i++)
        {
            int c=0;
            while(j<m&&c<cap&&p[j]<=b[i])
            {
                if(p[j]-1!=prev)
                    ans=p[j]-1;
                prev=p[j];
                c++;
                j++;
            }
            if(c<cap&&b[i]!=prev)
                ans=b[i];
        }
        return ans;
        
    }
};
