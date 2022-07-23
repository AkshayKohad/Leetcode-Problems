// Method 1
class Solution {
public:
    
    bool solve(int curr,unordered_set<int>&s,int &dest,int k,map<pair<int,int>,bool>&m)
    {
        if(curr==dest)
            return true;
        
        if(s.find(curr)==s.end())
            return false;
        
        
        if(m.find({curr,k})!=m.end())
            return m[{curr,k}];
        
        if(k==0)
            return m[{curr,k}] = solve(curr+k+1,s,dest,k+1,m);
        
        if(k==1)
            return m[{curr,k}] =  solve(curr+k,s,dest,k,m) || solve(curr+k+1,s,dest,k+1,m);
        
        
    return m[{curr,k}] = solve(curr+k,s,dest,k,m) || solve(curr+k-1,s,dest,k-1,m) || solve(curr+k+1,s,dest,k+1,m);
            
    }
    bool canCross(vector<int>& stones) {
        
        unordered_set<int>s;
        
        for(int i=1;i<stones.size()-1;i++)
        {
            s.insert(stones[i]);
        }
        
        int k=1;
        
        map<pair<int,int>,bool>m;
      return solve(1,s,stones[stones.size()-1],1,m);
        return false;
        
    }
};


//Method 2

class Solution {
public:
    
    bool solve(int i,int k,unordered_map<int,int>&mp,vector<int>&stones,vector<vector<int>>&memo,int &n)
    {
        if(i==n-1)
            return true;
        
        if(memo[i][k]!=-1)
            return memo[i][k];
        
        
        bool val = false;
        if(i==0)
        {
            if(mp.find(stones[i]+k+1)!=mp.end())
            {
                val = val || solve(mp[stones[i]+k+1],k+1,mp,stones,memo,n);
            }
        }
        
        else{
            
            if(mp.find(stones[i]+k)!=mp.end())
            {
                 val = val || solve(mp[stones[i]+k],k,mp,stones,memo,n);
            }
            
            if(mp.find(stones[i]+k+1)!=mp.end())
            {
                val = val || solve(mp[stones[i]+k+1],k+1,mp,stones,memo,n);
            }
            
            if(mp.find(stones[i]+k-1) != mp.end() && mp[stones[i]+k-1] > i)
            {
                val = val || solve(mp[stones[i]+k-1],k-1,mp,stones,memo,n);
            }
        }
        
        return memo[i][k] = val;
    }
    
    
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>mp;
        
        int n = stones.size();
        for(int i=0;i<n;i++)
        {
            mp[stones[i]] = i;    
        }
        
        vector<vector<int>>memo(n,vector<int>(n,-1));
        
        
        return solve(0,0,mp,stones,memo,n);
        
    }
};
