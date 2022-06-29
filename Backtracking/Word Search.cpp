class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    bool solve(int i,int j,vector<vector<int>>&visited,vector<vector<char>>&board,string word,int n)
    {
        if(n==word.length())
            return true;
        
        for(auto k : directions)
        {
            int x = i + k.first;
            int y = j + k.second;
            
            if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || visited[x][y]==1 || board[x][y]!=word[n])
                continue;
            
            visited[x][y] = 1;
            bool check = solve(x,y,visited,board,word,n+1);
            if(check==true)
                return true;
            visited[x][y] = 0;    
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<pair<int,int>>a;
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(word[0] == board[i][j])
                    a.push_back({i,j});
            }
        }
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<a.size();i++)
        {
            int x = a[i].first;
            int y = a[i].second;
            visited[x][y] = 1;
            
            if(solve(x,y,visited,board,word,1))
                return true;
            
            visited[x][y] = 0;
        }
        
        return false;
        
    }
};
