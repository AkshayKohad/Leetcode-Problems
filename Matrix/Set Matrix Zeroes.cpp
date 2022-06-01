class Solution {
public:
    

    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool row = false;
        bool column = false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    if(matrix[i][j] == 0)
                    {
                        row = true;
                        column = true;
                    }
                    continue;
                }
                
                else if(i==0)
                {
                    if(matrix[i][j]==0)
                        row = true;
                    
                    continue;
                }
                
                else if(j==0)
                {
                    if(matrix[i][j] == 0)
                        column = true;
                    continue;
                    
                }
                
                else{
                if(matrix[i][j]==0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
                    
                }
                
            }
            
            
        }
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(row == true)
        {
            for(int j=0;j<m;j++)
            {
                matrix[0][j] = 0;
            }
        }
        
        if(column == true)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0] = 0;
            }
        }
        
    }
};
