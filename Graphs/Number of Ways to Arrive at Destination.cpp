class Solution {
public:
#define ll long long
#define mod 1000000007
 
    int countPaths(int n, vector<vector<int>>& roads) {

      vector<ll>min_dist(n,1e15);
      vector<ll>count(n,0);
      vector<pair<ll,ll>>adj[n];

      for(ll i=0;i<roads.size();i++)
      {
          ll x = roads[i][0];
          ll y = roads[i][1];

          ll w = roads[i][2];

          adj[x].push_back({y,w});
          adj[y].push_back({x,w});


      }   

      priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

      pq.push({0,0});
      min_dist[0] = 0;
      count[0] = 1;

      while(pq.size()>0)
      {
          pair<ll,ll>cur = pq.top();
          pq.pop();

          ll dist = cur.first;
          ll nd = cur.second;

          for(auto u : adj[nd])
          {
              ll adj_nd = u.first;
              ll adj_dist = u.second;

              if(min_dist[adj_nd] > dist+adj_dist)
              {
                  min_dist[adj_nd] = dist+adj_dist;
                  pq.push({min_dist[adj_nd],adj_nd});
                  count[adj_nd] = count[nd];
              }
              else if(min_dist[adj_nd] == dist + adj_dist)
              {
                     count[adj_nd] = (count[adj_nd]+count[nd])%mod;
              }
          }
      }


   

    return count[n-1]%mod;
   
    }
};
