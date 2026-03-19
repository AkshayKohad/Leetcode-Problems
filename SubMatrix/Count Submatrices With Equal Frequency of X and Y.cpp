class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>prefix_x(n,vector<int>(m,0));
        vector<vector<int>>prefix_y(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // for 'X'
                int left = 0;
                int top = 0;
                int diagonal = 0;

                if(i-1>=0){
                    top = prefix_x[i-1][j];
                }
                if(j-1>=0){
                    left = prefix_x[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    diagonal = prefix_x[i-1][j-1];
                }

                prefix_x[i][j] = left + top - diagonal + (grid[i][j] == 'X' ? 1 : 0);


                left = 0;
                top = 0;
                diagonal = 0;

                if(i-1>=0){
                    top = prefix_y[i-1][j];
                }
                if(j-1>=0){
                    left = prefix_y[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    diagonal = prefix_y[i-1][j-1];
                }

                prefix_y[i][j] = left + top - diagonal + (grid[i][j] == 'Y' ? 1 : 0);
            }
        }

        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(prefix_x[i][j] == prefix_y[i][j]  && prefix_x[i][j]>0)result++;
            }
        }

        return result;
    }
};
