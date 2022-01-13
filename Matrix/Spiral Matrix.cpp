class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        
        int start_row = 0;
        int start_col = 0;
        int end_row = matrix.size()-1;
        int end_col = matrix[0].size()-1;
        
        vector<int>a;
        while(start_row<=end_row && start_col<=end_col)
        {
            
            for(int j=start_col;j<=end_col;j++)
            {
                a.push_back(matrix[start_row][j]);
            }
            
            start_row++;
            
            if(start_row>end_row || start_col>end_col)
               {
                   break;
               }
            
            for(int j=start_row;j<=end_row;j++)
            {
                a.push_back(matrix[j][end_col]);
            }
            
            end_col--;
               
               if(start_row>end_row || start_col>end_col)
               {
                   break;
               }
            
              for(int j=end_col;j>=start_col;j--)
              {
                a.push_back(matrix[end_row][j]);
              }
            
            end_row--;
                  if(start_row>end_row || start_col>end_col)
               {
                   break;
               }
            
            
              for(int j=end_row;j>=start_row;j--)
            {
                a.push_back(matrix[j][start_col]);
            }
            
            start_col++;
                     if(start_row>end_row || start_col>end_col)
               {
                   break;
               }
        }
        
        return a;
        
        
    }
};
