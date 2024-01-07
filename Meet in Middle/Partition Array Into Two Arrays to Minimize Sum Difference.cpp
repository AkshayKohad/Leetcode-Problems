class Solution {
public:

   void solve(vector<int>&w,map<int,vector<int>>&m,int &n,int i,int sum,int cnt)
   {
      

       if(i==n)
       {
         //if(cnt!=0)  
         m[cnt].push_back(sum);
         return;
       }

       solve(w,m,n,i+1,sum+w[i],cnt+1);
       solve(w,m,n,i+1,sum,cnt);
   }
    int minimumDifference(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<int>a;
        vector<int>b;
       int sum = 0;
        for(int i=0;i<n/2;i++)
        {
            a.push_back(nums[i]);
            sum+= nums[i];
            
        }
        
        for(int i=n/2;i<n;i++)
        {
            b.push_back(nums[i]);
            sum+= nums[i];
        }

        map<int,vector<int>>mpa;
        map<int,vector<int>>mpb;

        int sz = n/2;
    
        solve(a,mpa,sz,0,0,0);
        solve(b,mpb,sz,0,0,0);

       for(int i=0;i<=sz;i++)
       {
           vector<int>q = mpb[i];
           sort(q.begin(),q.end());

           mpb[i] = q;
       }

       int result = INT_MAX;

       
       int res_sum = sum/2;
       result = min(result,abs(sum-mpa[sz][0]-mpa[sz][0]));
       result = min(result,abs(sum-mpb[sz][0]-mpb[sz][0]));

        for(auto k:mpa)
        {
            vector<int>t =  k.second;
            int r = k.first;
           if(r==sz)
           continue;
            vector<int>u = mpb[sz-r];
           int size_u = u.size();
        
            for(auto i:t)
            {
                   vector<int>::iterator lower;
                   lower = lower_bound(u.begin(), u.end(), res_sum-i);
                   int ind = lower-u.begin();
                     
                   ind = min(size_u-1,ind);  
                      int f = sum-i-u[ind];
                      int s = i+u[ind];
                       
                      result = min(result,abs(f-s));
                
                 ind = min(size_u-1,ind+1);  
                   f = sum-i-u[ind];
                   s = i+u[ind];
                  result = min(result,abs(f-s));
            }
         
        }

        return result;
    }
};
