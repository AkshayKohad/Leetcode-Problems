class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {

     int n = coins.size();

     vector<int>adj[n];

     for(int i=0;i<edges.size();i++)
     {
         int x = edges[i][0];
         int y = edges[i][1];

         adj[x].push_back(y);
         adj[y].push_back(x);
     }   

     queue<int>q;
     for(int i=0;i<n;i++)
     {
         if(adj[i].size()==1)
         {
             q.push(i);
         }

     }

int total_nodes = n;
 queue<int>leaf_nodes_with_coins;
     // Process of trimming
     while(q.empty()==false)
     {
          int cur_node = q.front();
          q.pop();
 
          if(coins[cur_node]==1)
          {
              leaf_nodes_with_coins.push(cur_node);
              continue;
          }
          for(auto u : adj[cur_node])
          {

              auto node = find(begin(adj[cur_node]),end(adj[cur_node]),u);
              auto adj_node = find(begin(adj[u]),end(adj[u]),cur_node);
              adj[cur_node].erase(node);
              adj[u].erase(adj_node);
              total_nodes--;

              if(adj[u].size()==1)
              {
                  q.push(u);
              }
          }
           
     }


 // since we can go atmost 2 edges to collect coins so we will find all nodes from which we can go to
 // all nodes with coins

 for(int i=0;i<2;i++)
 {
     int size = leaf_nodes_with_coins.size();

     for(int j=0;j<size;j++)
     {
         int cur_node = leaf_nodes_with_coins.front();
         leaf_nodes_with_coins.pop();
  
           for(auto u : adj[cur_node])
          {

              auto node = find(begin(adj[cur_node]),end(adj[cur_node]),u);
              auto adj_node = find(begin(adj[u]),end(adj[u]),cur_node);
              adj[cur_node].erase(node);
              adj[u].erase(adj_node);
              total_nodes--;

              if(adj[u].size()==1)
              {
                  leaf_nodes_with_coins.push(u);
              }
          }
         
     }
 }
    
  if(total_nodes==0)
  return 0;

     return (total_nodes-1)*2;


    }
};
