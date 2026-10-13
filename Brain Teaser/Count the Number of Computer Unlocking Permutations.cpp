class Solution {
public:
    #define MOD 1000000007 
    int countPermutations(vector<int>& complexity) {
        int startComplexity = complexity[0];
        int n = complexity.size();
        for(int i=1;i<n;i++){
            if(startComplexity >= complexity[i])return 0;
        }

        int ans = 1;
        for(int i=1;i<=n-1;i++){
            ans = ((long long)ans*i)%MOD;
        }
        return ans;
    }
};
