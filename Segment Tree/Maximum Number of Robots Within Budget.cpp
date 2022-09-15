class Solution {
public:
    
    #define ll long long 
    
    void buildTree(vector<ll>&tree,ll s,ll e,vector<int>&chargeTimes,ll index)
    {
        if(s>e) return;
        
        if(s==e)
        {
            tree[index] = chargeTimes[s];
            return;
        }
        
        ll mid = (s+e)/2;
        
        buildTree(tree,s,mid,chargeTimes,2*index);
        buildTree(tree,mid+1,e,chargeTimes,2*index+1);
        
        
        tree[index] = max(tree[2*index],tree[2*index+1]);
        
        return;
        
    }
    
    ll query(vector<ll>&tree,ll ss,ll se,ll &qs,ll &qe,ll index)
    {
        //complete overlap
        if(ss>=qs && se<=qe) return tree[index];
        
        // no overlap
        if(ss>qe || se<qs) return INT_MIN;
        
        //partial overlap
        
        ll mid = (ss+se)/2;
        
        ll left = query(tree,ss,mid,qs,qe,2*index);
        
        ll right = query(tree,mid+1,se,qs,qe,2*index+1);
        
        return max(left,right);
        
    }
    
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        ll n = chargeTimes.size();
        
        
        vector<ll>tree(4*n+1,0);
        
        buildTree(tree,0,n-1,chargeTimes,1);
        
        vector<ll>prefix(n,0);
        
        prefix[0] = runningCosts[0];
        
        for(ll i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + runningCosts[i];
        }
        
        
        ll i=0;
        ll j=0;
        
        ll res = 0;
        while(j<n)
        {
            ll charge = query(tree,0,n-1,i,j,1);
            
            ll val = prefix[j] - prefix[i] + runningCosts[i];
            
            ll cur = charge + (j-i+1)*val;
            
          //  cout<<cur<<" "<<j<<" "<<i<<endl;
            
            if(cur<=budget)
            {
                res = max(res,j-i+1);
                
                
                j++;
            }
            
            else{
                i++;
                
                if(i>j)
                {
                    j=i;
                }
            }
            
        }
        
        return res;
    }
};
