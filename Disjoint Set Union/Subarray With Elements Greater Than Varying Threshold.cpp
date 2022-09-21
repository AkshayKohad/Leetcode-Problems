class Solution {
public:
    
    #define ll long long
    
    
    ll find(ll i,vector<ll>&parent)
    {
        if(parent[i]==-1) return i;
        
        return parent[i] = find(parent[i],parent);
    }
    
    void unite(ll n1, ll n2,vector<ll>&parent,vector<ll>&rank)
    {
        ll par1 = find(n1,parent);
        
        ll par2 = find(n2,parent);
        
        
        if(par1!=par2)
        {
            if(rank[par1]>=rank[par2])
            {
                rank[par1] += rank[par2];
                
                parent[par2] = par1;
            }
            
            else{
                rank[par2] += rank[par1];
                
                parent[par1] = par2;
                
            }
        }
        
    }
    
    
    static bool mycmp(pair<ll,ll>f,pair<ll,ll>s)
    {
        return f.first>s.first;
        
    }
    
    int validSubarraySize(vector<int>& nums, int threshold) {
        
        vector<pair<ll,ll>>a;
        
        ll n = nums.size();
        for(ll i=0;i<n;i++)
        {
            a.push_back({nums[i],i});
        }
        
        sort(a.begin(),a.end(),mycmp);
        
        vector<ll>parent(n,-1);
        
        vector<ll>rank(n,1);
        
        vector<bool>visited(n,false);
        for(ll i=0;i<n;i++)
        {
            ll val = a[i].first;
            ll index = a[i].second;
            
            visited[index] = true;
            if(index-1>=0 && visited[index-1]==true)
            {
                unite(index,index-1,parent,rank);
            }
            
            if(index+1<n && visited[index+1]==true)
            {
                unite(index,index+1,parent,rank);
            }
            
            ll par = find(index,parent);
            
            ll k = rank[par];
            
            if(k*(ll)nums[index] > (ll)threshold) return k;
        }
        
        return -1;
    }
};
