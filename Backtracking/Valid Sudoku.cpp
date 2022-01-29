class Solution {
public:
    
    
    bool check(int i,int j,vector<vector<char>>&board)
    {
        if(board[i][j]=='.')
            return true;
        
         char ch = board[i][j];
        for(int k=0;k<9;k++)
        {
            if(k!=i)
            {
                if(board[k][j]==ch)
                {
                    return false;
                }
            }
            
            if(k!=j)
            {
                if(board[i][k]==ch)
                {
                    return false;
                }
            }
        }
        
         int row_start = i - i%3;
        int col_start = j - j%3;
        
         for(int m = row_start;m<row_start+3;m++)
        {
            for(int k=col_start;k<col_start+3;k++)
            {
                if(board[m][k]==ch && m!=i && k!=j)
                    return false;
            }
        }
        
        
        return true;
        
    }
    
    
    bool solve(int i,int j,vector<vector<char>>&board)
    {
        if(i==9)
            return true;
        
        if(j==9)
        {
            return solve(i+1,0,board);
        }
        
        if(check(i,j,board))
        {
            return solve(i,j+1,board);
        }
        
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
       return solve(0,0,board);
        
    }
};
