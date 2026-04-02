class Solution {
public:
    int find(vector<int>&parent,int par){
        if(parent[par]==-1)return par;

        return parent[par] = find(parent,parent[par]);
    }

    void unite(int nd1,int nd2,vector<int>&parent,vector<int>&rank){
        int par1 = find(parent,nd1);
        int par2 = find(parent, nd2);

        if(par1==par2)return;

        if(rank[par1]>=rank[par2]){
            rank[par1] += rank[par2];
            parent[par2] = par1;
        }else{
            rank[par2] += rank[par1];
            parent[par1] = par2;
        }
    }
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,int>x_record;
        unordered_map<int,int>y_record;

        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        
        for(int i=0;i<n;i++){
            int cur_x = points[i][0];
            int cur_y = points[i][1];

            if(x_record.find(cur_x)==x_record.end())x_record[cur_x] = i;
            else{
                unite(x_record[cur_x],i,parent,rank);
            }

            if(y_record.find(cur_y)==y_record.end())y_record[cur_y] = i;
            else{
                unite(y_record[cur_y],i,parent,rank);
            }

        }

        vector<int>result;
        for(int i=0;i<n;i++){
           if(parent[i]==-1)result.push_back(rank[i]);
        }
        sort(result.begin(),result.end(),greater<>());

        if(result.size()>1)return result[0]+result[1]+1;

        return result[0]+1;
    }
};
