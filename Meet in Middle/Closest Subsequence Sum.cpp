class Solution {
public:

   void solve(vector<int>&a,int &n,int i,int sum,vector<int>&partition)
   {
       if(i==a.size())
       {
           partition.push_back(sum);
           return;
       }

       solve(a,n,i+1,sum+a[i],partition);
       solve(a,n,i+1,sum,partition);


   }
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int n = nums.size();
        int sz = n/2;

        vector<int>a;
        vector<int>b;

        for(int i=0;i<sz;i++)
        {
            a.push_back(nums[i]);
        }

        for(int i=sz;i<n;i++)
        {
            b.push_back(nums[i]);
        }

        vector<int>partition_1;
        solve(a,sz,0,0,partition_1);

        vector<int>partition_2;
        solve(b,sz,0,0,partition_2);


        sort(partition_2.begin(),partition_2.end());

       int result = INT_MAX;
        for(int i=0;i<partition_1.size();i++)
        {
            vector<int>::iterator lower;
            lower = lower_bound(partition_2.begin(), partition_2.end(), goal-partition_1[i]);

            int ind = lower - partition_2.begin();
            
            int sz_b = partition_2.size()-1;
            ind = min(sz_b,ind);
            
            result = min(result,abs(goal-partition_1[i]-partition_2[ind]));

            ind = max(0,ind-1);
            
            result = min(result,abs(goal-partition_1[i]-partition_2[ind]));

        } 
         
         return result;
    }
};
