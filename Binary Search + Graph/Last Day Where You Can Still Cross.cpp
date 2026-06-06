class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};

    bool check(int days,vector<vector<int>>&cells,int row,int col){
        vector<vector<int>>grid(row,vector<int>(col,0));

        for(int i=0;i<=days;i++){
            int x = cells[i][0] -1;
            int y = cells[i][1] -1;
            grid[x][y] = 1;
        }

        queue<pair<int,int>>q;
        vector<vector<int>>visited(row,vector<int>(col,0));

        for(int i=0;i<col;i++){
            if(grid[0][i] == 0){
                visited[0][i] = 1;
                q.push({0,i});
            }
        }
        

        while(q.empty()==false){
            pair<int,int>cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;

            if(x == row-1)return true;

            for(auto dir : directions){
                int next_x = x + dir.first;
                int next_y = y + dir.second;

                if(next_x < 0 || next_y < 0 || next_x >= row || next_y >= col || visited[next_x][next_y] == 1 || grid[next_x][next_y] == 1)continue;

                q.push({next_x,next_y});
                visited[next_x][next_y] = 1;
            }
        }

        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0;
        int r = cells.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = (r-l)/2 + l;

            if(check(mid,cells,row,col)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans+1;
    }
};
