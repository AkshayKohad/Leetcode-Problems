class Solution {
public:
#define ll long long
    vector<pair<ll,ll>>directions = {{1,0},{0,1},{0,-1},{-1,0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        ll n = moveTime.size();
        ll m = moveTime[0].size();

        vector<vector<ll>>visited(n,vector<ll>(m,LLONG_MAX));
        ll result = LLONG_MAX;
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>q;
        q.push({0,0,0,0});
        visited[0][0] = 0;
        
        while(!q.empty()){
            vector<ll>cur = q.top();
            q.pop();

            ll i = cur[1];
            ll j = cur[2];
            ll cur_time = cur[0];
            ll next_move = cur[3];
            
            if(i==n-1 && j==m-1){
                return cur_time;
            }
            
            if(cur_time > visited[i][j])continue;
        
            for(auto k:directions){
                ll x = i+k.first;
                ll y = j+k.second;

                if(x>=n || y>=m || x<0 || y<0)continue;
                int val = 1;
                if(next_move)val++;
                    
                ll res_time = max(cur_time,(ll)moveTime[x][y])+val;
                if(res_time < visited[x][y]){
                    visited[x][y] = res_time;
                    q.push({res_time,x,y,1-next_move});
                }
                
            }
        }
        //cout<<result<<endl;
        return -1;
    }
};
