class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        
        int countX = 0;
        int countO = 0;
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].length();j++)
            {
                if(board[i][j]=='X')
                    countX++;
                
                else if(board[i][j]=='O')
                    countO++;
            }
        }
        
        int flagX=0;
        int flagO=0;
        
        // for columns
        for(int i=0;i<board.size();i++)
        {
            int temp_countO=0;
            int temp_countX=0;
            for(int j=0;j<board[i].length();j++)
            {
                if(board[i][j]=='X')
                    temp_countX++;
                
                else if(board[i][j]=='O')
                    temp_countO++;
            }
            
            if(temp_countX==3)
                flagX = 1;
             if(temp_countO==3)
                 flagO = 1;
        }
        
        if(flagX==1 && flagO==1)
            return false;
        
        //for rows
        
         for(int i=0;i<board.size();i++)
        {
            int temp_countO=0;
            int temp_countX=0;
            for(int j=0;j<board[i].length();j++)
            {
                if(board[j][i]=='X')
                    temp_countX++;
                
                else if(board[j][i]=='O')
                    temp_countO++;
            }
            
            if(temp_countX==3)
                flagX = 1;
             if(temp_countO==3)
                 flagO = 1;
        }
        
        if(flagX==1 &&flagO==1)
            return false;
        
        // for diagonals
          int temp_countO=0;
            int temp_countX=0;
        for(int i=0;i<board.size();i++)
        {
            if(board[i][i]=='X')
                    temp_countX++;
                
                else if(board[i][i]=='O')
                    temp_countO++;
        }
         if(temp_countX==3)
                flagX = 1;
             if(temp_countO==3)
                 flagO = 1;
        if(flagX==1 && flagO==1)
            return false;
        
        // second diagonal
        temp_countO=0;
        temp_countX=0;
        int j= board.size()-1;
        int i=0;
        
        while(j>=0 && i<board.size())
        {
            if(board[j][i]=='X')
                    temp_countX++;
                
                else if(board[j][i]=='O')
                    temp_countO++;
            
            j--;
            i++;
        }
        
        if(temp_countX==3)
                flagX = 1;
             if(temp_countO==3)
                 flagO = 1;
        if(flagX==1 && flagO==1)
            return false;
        
        if(countO>countX)
            return false;
        if(countO<countX)
        {
            if(countX==countO+1 && flagO==0)
                return true;
            return false;
        }
        
        if(countX==countO && flagX==0)
        return true;
        
        return false;
        
    }
};
