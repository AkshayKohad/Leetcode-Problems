class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> result(n,vector<int>(m,0));
        queue<vector<int>> q;
        map<pair<int,int>,int> mp;

        for(auto source : sources){
            q.push({source[0],source[1],source[2],0});
            result[source[0]][source[1]] = source[2];
            mp[{source[0],source[1]}] = 0;
        }

        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

        while(q.size()>0){
            vector<int> cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];
            int color = cur[2];
            int cur_time = cur[3];

            for(auto direction : directions){
                int next_x = x + direction.first;
                int next_y = y + direction.second;

                if(next_x<0 || next_y<0 || next_x>=n || next_y>=m) continue;

                if(mp.find({next_x,next_y})==mp.end()){
                    mp[{next_x,next_y}] = cur_time+1;
                    result[next_x][next_y] = color;
                    q.push({next_x,next_y,color,cur_time+1});
                }else{
                    if(mp[{next_x,next_y}] > cur_time+1){
                        mp[{next_x,next_y}] = cur_time+1;
                        result[next_x][next_y] = color;
                        q.push({next_x,next_y,color,cur_time+1});
                    }else if(mp[{next_x,next_y}] == cur_time+1){
                        int prev_color = result[next_x][next_y];
                        int new_color = max(prev_color, color);

                        result[next_x][next_y] = new_color;

                        if(prev_color < color){
                            q.push({next_x,next_y,color,cur_time+1});
                        }
                    }
                }
            }
        }

        return result;
    }
};
