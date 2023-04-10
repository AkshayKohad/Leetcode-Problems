class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        dist[0][0] = 0;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0});

        while(pq.size()>0)
        {
            vector<int>cur = pq.top();
            pq.pop();
            int curx = cur[1];
            int cury = cur[2];

            int steps = cur[0];

            if(curx == n-1 && cury == m-1)
            return steps+1;

        
            for(int k=1;k<=grid[curx][cury];k++)
            {
                int newx = curx+k;
                int newy = cury;

                if(newx<n && dist[newx][newy] > steps+1)
                {
                    dist[newx][newy] = steps + 1;
                    if(newx == n-1 && newy == m-1) return steps+2;
                    pq.push({steps+1,newx,newy});
                    
                }
            } 

            for(int k=1;k<=grid[curx][cury];k++)
            {
                int newx = curx;
                int newy = cury+k;

                if(newy<m && dist[newx][newy] > steps+1)
                {
                    dist[newx][newy] = steps + 1;
                    if(newx == n-1 && newy == m-1) return steps+2;
                    pq.push({steps+1,newx,newy});

                   
                }
            } 

            
        }

        return -1;
    }
};
