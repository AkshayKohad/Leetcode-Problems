class Solution {
public:
    void find_end_node(int src,vector<int>adj[],int par,int &max_dist,int &end_node,int dist){
       
        if(max_dist<dist){
            end_node = src;
            max_dist = dist;
        }

        for(auto child : adj[src]){
            if(child == par)continue;

            find_end_node(child,adj,src,max_dist,end_node,dist+1);
        }

        return;
    }

    void find_dis(int src,vector<int>adj[],vector<int>&find_distance,int distance,int par){
        find_distance[src] = distance;

        for(auto child : adj[src]){
            if(child == par)continue;

            find_dis(child,adj,find_distance,distance+1,src);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
           vector<int>adj[n];
           for(int i=0;i<edges.size();i++){
              adj[edges[i][0]].push_back(edges[i][1]);
              adj[edges[i][1]].push_back(edges[i][0]);
           }
            int max_dist = 0;
            int end_node = 0;
           find_end_node(0,adj,-1,max_dist,end_node,0);

           int end_node2 = 0;
           max_dist = 0;
           find_end_node(end_node,adj,-1,max_dist,end_node2,0);

            // cout<<end_node<<" "<<end_node2<<"\n";
            vector<int>find_dist(n,0);
            find_dis(end_node,adj,find_dist,0,-1);
            vector<int>find_dist2(n,0);
            find_dis(end_node2,adj,find_dist2,0,-1);

            int res_dist = n+1;

            for(int i=0;i<n;i++){
                res_dist = min(res_dist,max(find_dist[i],find_dist2[i]));
            }

            vector<int>res_root;
            for(int i=0;i<n;i++){
                if(res_dist==max(find_dist[i],find_dist2[i]))
                    res_root.push_back(i);
            }
           return res_root;
    }
};
