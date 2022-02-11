class Solution {
public:
    
    
    void solve(int src,vector<int>adj[],vector<int>&visited,vector<int>temp,bool &flag)
    {
        visited[src] = 1;
        temp[src] = 1;
        //cout<<src<<endl;
        for(auto u : adj[src])
        {
            if(visited[u]==0)
            {
                solve(u,adj,visited,temp,flag);
            }
            if(flag==true)
            {
                //cout<<"hello"<<endl;
                return;
            }
            
            if(temp[u]==1)
            {
                flag = true;
             //   cout<<"hello"<<endl;
                return;
            }
        }
       // cout<<src<<endl;
       
        temp[src] = 0;
        
        
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses;
        vector<int>adj[n];
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
      
        vector<int>visited(n,0);
        vector<int>temp(n,0);
       
        bool flag=false;
        for(int i=0;i<n;i++)
        {
         if(visited[i]==0)   
        solve(i,adj,visited,temp,flag);
            
            if(flag==true)
            {
              return false;   
            }
        }
        
        
        
        return true;
    }
};
