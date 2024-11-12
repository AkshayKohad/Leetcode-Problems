class Solution {
public:
    int solve(int nd,vector<int>adj[],string &s,int &result){
        int res = 1;
        int cur_char = s[nd];
        int first_max = 0;
        int second_max = 0;
        for(auto child : adj[nd]){
            int cur = solve(child,adj,s,result);

            if(s[child] == cur_char)result = max(result,cur);
            else{
                if(first_max <= cur){
                    second_max = first_max;
                    first_max = cur;
                }
                else if(second_max < cur)second_max = cur;
            }
        }
        //cout<<nd<<" "<<first_max<<" "<<second_max<<endl;
        result = max(result,res+first_max+second_max);
        return res+max(first_max,second_max);
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int>adj[n];

        for(int i=1;i<n;i++){
            int par = parent[i];
            int child = i;

            adj[par].push_back(child);
        }
        int result = 0;
        solve(0,adj,s,result);

        return result;
    }
};
