class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        
        queue<pair<int,int>>q;
        
        
        int n = heights.size();
        int m = heights[0].size();
        // let Atlantic be 1 and pacific be 2
        vector<vector<int>>values(n,vector<int>(m,0));
        
        // left border
        
        for(int i=0;i<n;i++)
        {
            
            
            if(i!=0 || i!=n-1 )
            {
                values[i][0] += 2;
                q.push({i,0});
            }
        }
        
        //bottom border
        
        for(int j=0;j<m;j++)
        {
            
            
            if(j!=0 || j!=m-1)
            {
                values[n-1][j] += 1;
                q.push({n-1,j});
            }
        }
        
        // right border
        
        for(int i=0;i<n;i++)
        {
            
            
            if(i!=0 || i!=n-1)
            {
                values[i][m-1] += 1;
                q.push({i,m-1});
            }
        }
        
        //top border
        
        for(int j=0;j<m;j++)
        {
            
            
            if(j!=0 || j!=m-1)
            {
             values[0][j] += 2;   
             q.push({0,j});   
            }
        }
        
        
        values[0][0] = 2;
        values[n-1][m-1] = 1;
         values[n-1][0] = 3;
        values[0][m-1] = 3;
        

        
        
        while(q.empty()==false)
        {
            pair<int,int>curr = q.front();
            q.pop();
            
            int i = curr.first;
            int j = curr.second;
            
            int val = values[i][j];
            
            int height = heights[i][j];
            
            for(auto k:directions)
            {
                int x = i + k.first;
                int y = j + k.second;
                
                if(x<0 || y<0 || x>=n || y>=m || values[x][y]==val || values[x][y] == 3)
                    continue;
                
                if(heights[x][y]<height)
                    continue;
                
                if(val!=3)
                  values[x][y] += val;
                
                else{
                    values[x][y] = 3;
                }
                
                  q.push({x,y});
            }
        }
        
        vector<vector<int>>res;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(values[i][j]==3)
                {
                    res.push_back({i,j});
                }
            }
        }
        
        return res;
        
      //  return {};
    }
};
