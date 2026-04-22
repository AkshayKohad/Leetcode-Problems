class Solution {
public:
    int count_walls(int l, int r, vector<int>& walls){
        if(l > r) return 0;
        auto it1 = lower_bound(walls.begin(), walls.end(), l);
        auto it2 = upper_bound(walls.begin(), walls.end(), r);
        return it2 - it1;
    }

    int solve(int i, int &n, vector<pair<int,int>>& rd, vector<int>& walls, int prev_dir, vector<vector<int>>& memo){
        if(i == n) return 0;

        if(memo[i][prev_dir] != -1) return memo[i][prev_dir];

        int pos = rd[i].first;
        int dist = rd[i].second;

        int next_pos = (i+1 < n ? rd[i+1].first : 1e9);
        int prev_pos = (i-1 >= 0 ? rd[i-1].first : -1e9);
        int prev_dist = (i-1 >= 0 ? rd[i-1].second : 0);

        // RIGHT interval
        int right_l = pos;
        int right_r = min(pos + dist, next_pos - 1);

        // LEFT interval
        int left_l = max(pos - dist, prev_pos + 1);
        int left_r = pos;

        int ans = 0;

        // ---- Case 1: Shoot RIGHT ----
        int walls_right = count_walls(right_l, right_r, walls);
        ans = max(ans, walls_right + solve(i+1, n, rd, walls, 1, memo));

        // ---- Case 2: Shoot LEFT ----
        int walls_left = count_walls(left_l, left_r, walls);

        if(prev_dir == 1){ 
            // previous was RIGHT → need to remove overlap

            int prev_right_l = prev_pos;
            int prev_right_r = prev_pos + prev_dist;

            int overlap_l = max(left_l, prev_right_l);
            int overlap_r = min(left_r, prev_right_r);

            int overlap = count_walls(overlap_l, overlap_r, walls);

            ans = max(ans, walls_left - overlap + solve(i+1, n, rd, walls, 2, memo));
        }
        else{
            // no overlap issue
            ans = max(ans, walls_left + solve(i+1, n, rd, walls, 2, memo));
        }

        return memo[i][prev_dir] = ans;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        sort(walls.begin(), walls.end());

        vector<pair<int,int>> rd;
        int n = robots.size();

        unordered_set<int> robot_pos;
        for(int i = 0; i < n; i++){
            rd.push_back({robots[i], distance[i]});
            robot_pos.insert(robots[i]);
        }

   
        sort(rd.begin(), rd.end());

        vector<vector<int>> memo(n, vector<int>(3, -1));

        return solve(0, n, rd, walls, 0, memo);
    }
};
