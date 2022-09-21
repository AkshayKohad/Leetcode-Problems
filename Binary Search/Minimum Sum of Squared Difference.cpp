class Solution {
public:
    
    #define ll long long 
    
    
    bool check(ll val,vector<ll>&nums,ll k)
    {
        ll total = 0;
        
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]>val)
            {
                total += nums[i]-val;
            }
        }
        
        if(total>k) return false;
        
        return true;
    }
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
    ll k = k1+k2;
        
    vector<ll>nums;
        
        ll n = nums1.size();
        
        ll maxi = 0;
        for(ll i=0;i<n;i++)
        {
            nums.push_back(abs(nums1[i]-nums2[i]));
            maxi = max(maxi,abs(nums.back()));
        }
        
        
        ll l = 0;
        
        ll r = maxi;
        
        ll ans = INT_MAX;
        
        while(l<=r)
        {
            ll mid = (l+r)/2;
            
            if(check(mid,nums,k))
            {
                ans = min(ans,mid);
                
                 r = mid-1;
            }
            
            else{
                l = mid+1;
            }
        }
        
        priority_queue<ll>pq;
        for(ll i=0;i<n;i++)
        {
            if(nums[i]>ans)
            {
                ll diff = nums[i]-ans;
                
                if(k>=diff)
                {
                nums[i] = nums[i]-diff;
                k = k-diff;
                }
            }
            
        }
        
        
        for(ll i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        
        
        if(pq.top()==0) return 0;
        
        while(pq.size()>0 && k>0)
        {
            ll val = pq.top();
            
            pq.pop();
            
            if(val==0) 
            continue;
            
            val = val-1;
            k = k-1;
            
            pq.push(val);
            
        }
        
        
        ll res = 0;
        
        while(pq.size()>0)
        {
          res += pq.top()*pq.top();
            
            pq.pop();
        }
        
        return res;
        
    }
};
