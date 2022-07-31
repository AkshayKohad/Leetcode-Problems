class Solution {
public:
    
    //int solve(int curr,int)
    int minJumps(vector<int>& a) {
        
        
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<a.size();i++)
        {
            mp[a[i]].push_back(i);
        }
        int n = a.size();
        
    vector<bool>visited(n,false);
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        visited[0] = true;
        
       
        while(q.empty()==false)
        {
            pair<int,int>curr = q.front();
            q.pop();
            
            int i = curr.first;
            int moves = curr.second;
            
            
                
            
            if(i-1>=0 && visited[i-1]==false)
            {
                
                
                    
                visited[i-1] = true;
                q.push({i-1,moves+1});
                
            }
            
            if(i+1<n && visited[i+1]==false)
            {
                if(i+1==n-1)
                    return moves+1;
                
                visited[i+1] = true;
                q.push({i+1,moves+1});
            }
            
            for(auto k : mp[a[i]])
            {
                if(visited[k]==false && k!=i)
                {
                    if(k==n-1)
                        return moves+1;
                    
                    visited[k] = true;
                    
                    q.push({k,moves+1});
                }
            }
            
            mp.erase(a[i]);
        }
        
        return 0;
    }
};
