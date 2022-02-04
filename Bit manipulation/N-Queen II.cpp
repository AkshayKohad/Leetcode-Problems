class Solution {
public:
    bitset<10>col,d1,d2;
    
    void solve(int r,int n, int &ans)
    {
        if(r==n)
        {
           ans++;
            return;
        }
        
        for(int c=0;c<n;c++)
        {
            if(d1[r+c]==0 && col[c]==0 && d2[n-1 + r-c]==0)
            {
                col[c] = d1[r+c] = d2[n-1 + r-c] = 1;
                solve(r+1,n,ans);
                col[c] = d1[r+c] = d2[n-1 + r-c] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        solve(0,n,ans);
        return ans;
    }
};
