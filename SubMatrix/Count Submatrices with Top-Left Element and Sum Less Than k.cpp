class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>prefix_sum(n,vector<int>(m,0));

        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int left = 0;
                int top = 0;
                int diagonal = 0;

                if(i-1>=0){
                    top = prefix_sum[i-1][j];
                }
                if(j-1>=0){
                    left = prefix_sum[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    diagonal = prefix_sum[i-1][j-1];
                }

                prefix_sum[i][j] = left + top - diagonal + grid[i][j];

                if(prefix_sum[i][j] <= k)result++;

            }
        }

        return result;    
    }
};
