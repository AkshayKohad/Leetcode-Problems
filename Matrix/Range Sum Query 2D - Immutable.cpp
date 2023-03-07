class NumMatrix {
public:

  vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        mat = vector<vector<int>>(n,vector<int>(m));

        mat[0][0] = matrix[0][0];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int result = 0;

                if(j-1>=0)
                {
                    result += mat[i][j-1];
                }

                if(i-1>=0)
                {
                    result += mat[i-1][j];
                }

                if(j-1>=0 && i-1>=0)
                {
                    result -= mat[i-1][j-1];
                }

                result += matrix[i][j];

                mat[i][j] = result;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

     int result = 0;

     if(row1-1>=0)
     {
         result += mat[row1-1][col2];
     }

     if(col1-1>=0)
     {
         result += mat[row2][col1-1];
     }

    if(row1-1>=0 && col1-1>=0)
    {
        result -= mat[row1-1][col1-1];
    }

    return mat[row2][col2] - result;
    }
};



/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// /**
//  * Your NumMatrix object will be instantiated and called as such:
//  * NumMatrix* obj = new NumMatrix(matrix);
//  * int param_1 = obj->sumRegion(row1,col1,row2,col2);
//  */
