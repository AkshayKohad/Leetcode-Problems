class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<int>row_count_1(n,0);
        vector<int>row_count_0(n,0);
        vector<int>column_count_1(m,0);
        vector<int>column_count_0(m,0);

        for(int i=0;i<n;i++)
        {
            int count_1 = 0;
            int count_0 = 0;
            for(int j=0;j<m;j++)
            {
                 if(grid[i][j]==1)
                 {
                   count_1++;
                 }
                 else{
                   count_0++;
                 }
            }

            row_count_1[i] = count_1;
            row_count_0[i] = count_0;
        }

        for(int j=0;j<m;j++)
        {
            int count_1 = 0;
            int count_0 = 0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==1)
                 {
                   count_1++;
                 }
                 else{
                   count_0++;
                 }
            }
            column_count_1[j] = count_1;
            column_count_0[j] = count_0;

        }

        vector<vector<int>>result(n,vector<int>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                result[i][j] = row_count_1[i] + column_count_1[j] - row_count_0[i] - column_count_0[j];
            }
        }
      return result;
    }
};
