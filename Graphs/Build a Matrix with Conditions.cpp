class Solution {
public:
    
  
  // for giving priority among the number in row and columns we use topological sort according to given row conditions and column conditions
  // Among topological sort we also check whether there is cycle present or not because if cycle is present then it contradicts some conditions
  
  
    vector<int>topological(vector<int>adj[],int k)
    {
        queue<int>q;
        
        vector<int>indegree(k+1,0);
        
        for(int i=1;i<=k;i++)
        {
        for(auto u:adj[i])
        {
            indegree[u]++;
        }
            
        }    
        
        vector<int>res;
        for(int i=1;i<=k;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        int cnt = 0;
        
        while(q.empty()==false)
        {
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            cnt++;
            
            for(auto u:adj[node])
            {
                indegree[u]--;
                
                if(indegree[u]==0)
                    q.push(u);
            }
        }
        
        if(cnt==k)
        {
            return res;
        }
        
        return {};
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        
        
        vector<int>top_adj[k+1];
        
        int n = rowConditions.size();
        for(int i=0;i<n;i++)
        {
            int top = rowConditions[i][0];
            int bottom = rowConditions[i][1];
            
            top_adj[top].push_back(bottom);
        }
        
        
        int m = colConditions.size();    
        vector<int>left_adj[k+1];
        
        for(int i=0;i<m;i++)
        {
            int left = colConditions[i][0];
            int right = colConditions[i][1];
            
            left_adj[left].push_back(right);
        }
        
        
        vector<int>row_sort = topological(top_adj,k);
        
        if(row_sort.size()==0) return {};
        
        vector<int>col_sort = topological(left_adj,k);
        
        if(col_sort.size()==0) return {};
        
        vector<int>rows(k+1);
        
        vector<int>columns(k+1);
        
        int index = 0;
        for(int i=0;i<row_sort.size();i++)
        {
            rows[row_sort[i]] = index;
            index++;
        }
        
        index=0;
        for(int i=0;i<col_sort.size();i++)
        {
            columns[col_sort[i]] = index;
            index++;
        }
        
        
        vector<vector<int>>matrix(k,vector<int>(k,0));
        
        for(int i=1;i<=k;i++)
        {
            matrix[rows[i]][columns[i]] = i;
        }
        return matrix;
    }
};
