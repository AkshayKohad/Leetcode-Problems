class Solution {
public:
    void solve(int src,vector<int>adj[],vector<int>updated_adj[],string &s,unordered_map<char,stack<int>>&mp){
        mp[s[src]].push(src);
        for(auto child : adj[src]){
            char ch = s[child];
            if(mp[ch].size()>0){
                int new_par = mp[ch].top();
                updated_adj[new_par].push_back(child);
            }else{
                updated_adj[src].push_back(child);
            }

            solve(child,adj,updated_adj,s,mp);
        }
        mp[s[src]].pop();
        
    }
    int find_size(int src,vector<int>adj[],vector<int>&result){
        int res = 1;
        for(auto child : adj[src]){
            res += find_size(child,adj,result);
        }
        result[src] = res;
        return res;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        
        vector<int>adj[n];
        for(int i=1;i<n;i++){
            int par = parent[i];
            int child = i;

            adj[par].push_back(child);
        }

        vector<int>updated_adj[n];
        unordered_map<char,stack<int>>mp;
        solve(0,adj,updated_adj,s,mp);

        vector<int>result(n,0);
        find_size(0,updated_adj,result);

        return result;
    }
};
