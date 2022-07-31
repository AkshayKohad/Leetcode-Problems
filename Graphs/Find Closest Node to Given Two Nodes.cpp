class Solution {
public:
    
    
    void bfs(int src,vector<int>adj[],map<int,int>s[],int n)
    {
        
        queue<pair<int,int>>q;
        
        q.push({src,0});
        
         vector<bool>visited(n,false);
        visited[src] = true;
        while(q.empty()==false)
        {
          
            
            pair<int,int>cur = q.front();
            q.pop();
            
            int i = cur.first;
            int count = cur.second;
        
        for(auto u : adj[i])
        {
            if(visited[u]==false)
            {
                visited[u]=true;
                
                if(s[src].find(u)!=s[src].end())
                {
                    s[src][u] = min(s[src][u],count+1);
                }
                
                else{
                    s[src][u] = count+1;
                }
                
                
                q.push({u,count+1});
                
                visited[u] = true;
            }
        }
            
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        
        int n = edges.size();
        vector<int>adj[n];
        
        
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1)
                continue;
            
            adj[i].push_back(edges[i]);
        }
        
        map<int,int>s[n];
        
        
       
        
       
        s[node1][node1] = 0;
       bfs(node1,adj,s,n);
        
        
        
        s[node2][node2] = 0;
        bfs(node2,adj,s,n);
       
        
        
        int res = INT_MAX;
        int res_node = INT_MAX;
        
        unordered_set<int>st;
        
        for(auto k:s[node1])
        {
            st.insert(k.first);
            cout<<k.first<<" ";
        }
        
        cout<<endl;
        
        for(auto k:st)
        {
            int ans = -1;
            if(s[node2].find(k)!=s[node2].end())
            {
                ans = max(s[node2][k],s[node1][k]);
            }
            if(ans!=-1)
            {
              if(res>ans)
              {
               res = min(ans,res);
                 res_node = k;
              }
                
                else if(res==ans)
                {
                    cout<<k<<endl;
                    res_node = min(k,res_node);
                }
            }
        }
        
        st.clear();
        
         for(auto k:s[node2])
        {
            st.insert(k.first);
             cout<<k.first<<" ";
        }
        
        for(auto k:st)
        {
            int ans = -1;
            if(s[node1].find(k)!=s[node1].end())
            {
                ans = max(s[node2][k],s[node1][k]);
            }
            if(ans!=-1)
            {
              if(res>ans)
              {
               res = min(ans,res);
                 res_node = k;
              }
                
                else if(res==ans)
                {
                    
                    res_node = min(k,res_node);
                }
            }
        }
        
        if(res == INT_MAX)
            return -1;
        
        
        return res_node;
    }
};
