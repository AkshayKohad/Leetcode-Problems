class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        
        vector<vector<int>> board_copy(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board_copy[i][j] = board[i][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                int live_count = 0;
                
                for(auto k:directions)
                {
                    int x = i+k.first;
                    int y = j+k.second;
                    
                    if(x<0 || y<0 || x>=n || y>=m)
                        continue;
                    
                    if(board_copy[x][y]==1)
                        live_count++;
                }
                
                if(board_copy[i][j]==1)
                {
                    if(live_count<2)
                        board[i][j]=0;
                    
                    else if(live_count>=2 && live_count<=3)
                        board[i][j]=1;
                    
                    else{
                        board[i][j]=0;
                    }
                    
                    
                }
                
                
                else{
                    if(live_count==3)
                        board[i][j] = 1;
                    
                    else
                        board[i][j] = 0;
                }
            }
        }
    }
};
