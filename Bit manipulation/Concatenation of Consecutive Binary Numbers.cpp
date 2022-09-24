class Solution {
public:
    #define MOD 1000000007
    int totalNofBits(int n)
    {
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long long ans = 0;
        
        for(int i=1;i<=n;i++)
        {
            ans  = ((ans<<totalNofBits(i))%MOD + i)%MOD;
        }
        return ans;
    }
};
