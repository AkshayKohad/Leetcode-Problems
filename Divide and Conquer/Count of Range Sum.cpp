class Solution {
public:
    
    #define ll long long
    
    ll merge(vector<ll>&prefix,ll start,ll mid,ll end,int lower,int upper)
    {
        ll count = 0;
        ll i;
        ll j = mid+1;
        ll k = mid+1;
        
        for(i=start;i<=mid;i++)
        {
            while(j<=end && prefix[j]-prefix[i]<lower)
                j++;
            
            while(k<=end && prefix[k]-prefix[i]<=upper)
                k++;
            
            count += k-j;
        }
        
        vector<ll>a;
        
        i = start;
        j = mid+1;
        
        while(i<=mid && j<=end)
        {
            if(prefix[i]<=prefix[j])
            {
                a.push_back(prefix[i]);
                i++;
            }
            
            else{
                a.push_back(prefix[j]);
                j++;
            }
        }
        
        while(i<=mid)
        {
           a.push_back(prefix[i]);
            i++;
        }
        
        while(j<=end)
        {
            a.push_back(prefix[j]);
            j++;
        }
        
        
        ll z = start;
        
        for(i=0;i<a.size();i++)
        {
            prefix[z] = a[i];
            z++;
        }
        
        return count;
        //return 0;
    }
    
    ll mergeSort(vector<ll>&prefix,ll start,ll end,int lower,int upper)
    {
        ll answer = 0;
        ll mid;
        
        if(start == end)
        {
            if(prefix[start]>=lower && prefix[start]<=upper)
            {
                return 1;
            }
            
            else
            {
                return 0;
            }
        }
        
        if(start>end)
            return 0;
         mid = (start+end)/2;
        
        answer += mergeSort(prefix,start,mid,lower,upper);
        
        answer += mergeSort(prefix,mid+1,end,lower,upper);
        
        answer += merge(prefix,start,mid,end,lower,upper);
        
        return answer;
//        return 0;
        
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        ll n = nums.size();
        
       vector<ll>prefix(n);
        
       prefix[0] = nums[0];
        
        for(ll i=1;i<n;i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }
        
        //return 0;
        return mergeSort(prefix,0,n-1,lower,upper);
    }
};
