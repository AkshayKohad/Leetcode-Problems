class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<pair<int,int>>edges;
        unordered_map<int,int>node_roads;

        for(auto road : roads){
            int nd1 = min(road[0],road[1]);
            int nd2 = max(road[0],road[1]);

            edges.insert({nd1,nd2});
            node_roads[nd1]++;
            node_roads[nd2]++;
        }
        int max_network = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int total_roads = 0;
                if(edges.find({i,j}) != edges.end())total_roads--;

                total_roads += node_roads[i] + node_roads[j];

                max_network = max(max_network,total_roads);
            }
        }
        return max_network;
    }
};
