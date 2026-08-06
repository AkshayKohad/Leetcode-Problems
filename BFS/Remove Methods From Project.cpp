class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>indegree(n,0);
        vector<int>adj[n];

        for(auto invocation : invocations){
            int invoker = invocation[0];
            int method = invocation[1];
            adj[invoker].push_back(method);
            indegree[method]++;
        }

        queue<int>q;
        q.push(k);
        vector<int>visited(n,0);
        visited[k] = 1;
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            for(auto next_nd : adj[nd]){
                if(visited[next_nd])continue;
                visited[next_nd] = 1;
                q.push(next_nd);
            }
        }

        bool isRemoveSuspiciousEdges = true;
        for(auto invocation : invocations){
            if(!visited[invocation[0]] && visited[invocation[1]]){
                isRemoveSuspiciousEdges = false;
                break;
            }
        }

        vector<int>result;
        
        if(isRemoveSuspiciousEdges){
            for(int i=0;i<n;i++){
                if(visited[i])continue;
                result.push_back(i);
            }
        }else{
            for(int i=0;i<n;i++){
                result.push_back(i);
            }
        }
        
        return result;
    }
};
