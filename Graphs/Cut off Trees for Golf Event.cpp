class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int bfs(int sx,int sy,int ex,int ey,vector<vector<int>>& forest)
    {
        int n = forest.size();
        int m = forest[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{sx,sy}});
        
        visited[sx][sy] = 1;
        
        while(q.empty()==false)
        {
            pair<int,pair<int,int>>curr = q.front();
            q.pop();
            
            int moves = curr.first;
            
            int i = curr.second.first;
            
            int j = curr.second.second;
            
            for(auto k:directions)
            {
                int x = i+k.first;
                int y = j+k.second;
                
                if(x==ex && y==ey) return moves+1;
                
                if(x<0 || x>=n || y<0 || y>=m || visited[x][y]==1 || forest[x][y]<1)
                    continue;
                
                q.push({moves+1,{x,y}});
            }
            
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
      
        if(forest.size()==0 || forest[0].size()==0)
            return 0;
        
       
        
        int n = forest.size();
        int m = forest[0].size();
        
       vector<pair<int, pair<int, int>>> trees;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(forest[i][j]>1)
                {
                  trees.push_back({forest[i][j],{i,j}});
                }
                    
            }
        }
        
        sort(trees.begin(),trees.end());
        
        if(trees[0].second.first !=0 || trees[0].second.second !=0)
        {
            trees.insert(trees.begin(),{0,{0,0}});
        }
           
        
        int ans = 0;
        for(int i=1;i<trees.size();i++)
        {
            auto prev = trees[i-1].second;
            
            auto curr = trees[i].second;
            
           int res = bfs(prev.first,prev.second,curr.first,curr.second,forest); 
            
            if(res==-1) return -1;
            
            ans += res;
        }
        
        return ans;
    }
};
