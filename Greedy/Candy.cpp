class Solution {
public:
    
    static bool mycmp(pair<int,int>f,pair<int,int>s)
    {
        return f.first<s.first;
    }
    
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        
        vector<int>visited(n,0);
        
        vector<int>ans(n,0);
        vector<pair<int,int>>res;
        
        for(int i=0;i<n;i++)
        {
            res.push_back({ratings[i],i});
        }
        
        sort(res.begin(),res.end(),mycmp);
        
        for(int i=0;i<n;i++)
        {
            pair<int,int>curr = res[i];
            
            int val = curr.first;
            int index = curr.second;
            
            visited[index] = 1;
            int cur_val = 1;
            
            if(index-1>=0 && visited[index-1]==1)
            {
               if(ratings[index-1]<ratings[index])
               {
                   cur_val = max(cur_val,ans[index-1]+1);
               }
            }
            
            if(index+1<n && visited[index+1]==1)
            {
                if(ratings[index+1]<ratings[index])
               {
                   cur_val = max(cur_val,ans[index+1]+1);
               }
            }
            
            ans[index] = cur_val;
        }
        
        int result = 0;
        
        for(int i=0;i<ans.size();i++)
        {
            result += ans[i];
        }
        
        return result;
    }
};
