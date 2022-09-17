class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>matrix(n,vector<int>(n));
        
         int start_row = 0;
        int start_col = 0;
        int end_row = n-1;
        int end_col = n-1;
        
        int count = 1;
        while(start_row<=end_row && start_col<=end_col)
        {
            
            for(int j=start_col;j<=end_col;j++)
            {
                matrix[start_row][j] = count;
                count++;
            }
            
            start_row++;
            
            if(start_row>end_row || start_col>end_col)
               {
                   break;
               }
            
            for(int j=start_row;j<=end_row;j++)
            {
                matrix[j][end_col] = count;
                count++;
            }
            
            end_col--;
               
               if(start_row>end_row || start_col>end_col)
               {
                   break;
               }
            
              for(int j=end_col;j>=start_col;j--)
              {
                  matrix[end_row][j] = count;
                  count++;
              }
            
            end_row--;
                  if(start_row>end_row || start_col>end_col)
               {
                   break;
               }
            
            
              for(int j=end_row;j>=start_row;j--)
            {
                matrix[j][start_col] = count;
                  count++;
            }
            
            start_col++;
                     if(start_row>end_row || start_col>end_col)
               {
                   break;
               }
        }
        
        return matrix;
    }
};
