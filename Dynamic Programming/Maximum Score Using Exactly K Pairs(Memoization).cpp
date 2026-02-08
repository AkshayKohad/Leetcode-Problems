class Solution {
public:
    
    long long solve(int i,int j, int &n, int &m,vector<int>&nums1,vector<int>&nums2,int k,vector<vector<vector<long long>>>&memo){
        if(k==0)return 0;
        if(i==n || j==m)return LLONG_MIN;

        if(memo[i][j][k]!=-1)return memo[i][j][k];

        long long result = LLONG_MIN;
        long long temp = solve(i+1,j+1,n,m,nums1,nums2,k-1,memo);
        if(temp!=LLONG_MIN)
            result = max(result,(long long)nums1[i]*(long long)nums2[j] + temp);

        result = max(result,solve(i+1,j,n,m,nums1,nums2,k,memo));
        result = max(result,solve(i,j+1,n,m,nums1,nums2,k,memo));

        return memo[i][j][k] = result;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<long long>>>memo(n,vector<vector<long long>>(m,vector<long long>(k+1,-1)));
        return solve(0,0,n,m,nums1,nums2,k,memo);

    }
};
