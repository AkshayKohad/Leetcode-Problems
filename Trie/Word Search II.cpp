class Solution {
public:
    
   vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}}; 
    
    class Trie{
        public:
         Trie *children[26];
        bool isEnd;
        int count;
        Trie()
        {
            isEnd = false;
            count=0;
            for(int i=0; i<26; i++)
            children[i]=NULL;
        }
        
    };
    
    
    void insert(Trie*root,string word)
    {
        Trie*curr = root;
        for(int i=0;i<word.length();i++)
        {
            int k = word[i]-'a';
            if(!curr->children[k])
                curr->children[k] = new Trie();
            curr = curr->children[k];
            curr->count++;
        }
        
        curr->isEnd = true;
    }
    
    
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>&visited,Trie*head,vector<string>&res,string &t,int &n,int &m)
    {
     
        if(head->isEnd==true)
        {
            res.push_back(t);
            head->isEnd = false;
        }
        
        for(auto w : directions)
        {
            int x = i+w.first;
            int y = j+w.second;
            
            if(x<0 || y<0 || x>=n || y>=m || visited[x][y] ==true)
                continue;
            
             int k = board[x][y]-'a';
           
            
            if(head->children[k]==NULL)
                continue;
            
             
            Trie*p = head->children[k];
            
            t.push_back(board[x][y]);
            
            visited[x][y] = true;
            
            dfs(x,y,board,visited,p,res,t,n,m);
            
            visited[x][y] = false;
            
            t.pop_back();
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie*root = new Trie;
        
        for(int i=0;i<words.size();i++)
        {
            insert(root,words[i]);
        }
        
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        
        vector<string>res;
        
          int flag = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                   if(root->children[board[i][j]-'a'])
                   {
                       
                       string t;
                       visited[i][j] = true;
                       Trie*p = root->children[board[i][j]-'a'];
                       t.push_back(board[i][j]);
                    
                       dfs(i,j,board,visited,p,res,t,n,m);
                           t.pop_back();
                        visited[i][j] = false;   
                       
                      
                   }  
                    
                }    
        }
        
       
        
        return res;
        
    }
};
