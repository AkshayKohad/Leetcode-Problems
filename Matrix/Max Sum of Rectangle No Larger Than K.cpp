class Solution {
public:

   int subarray_sum_not_greater_than_k(vector<int>&arr,int k)
   {
       //cout<<k<<endl;
       set<int>cum_set;
       int c_sum = 0;
       int max_sum = INT_MIN;
       
       
       for(int i=0;i<arr.size();i++)
       {
           c_sum += arr[i];

         //  cout<<c_sum<<endl;
            if(c_sum<=k)
            {
                max_sum = max(max_sum,c_sum);
            }

          
           auto it = cum_set.lower_bound(c_sum-k);

           // this will give the sum close to k
           if(it!=cum_set.end())
           {
              max_sum = max(max_sum,c_sum-*it);
           }

           cum_set.insert(c_sum);
       }
     // cout<<max_sum;
       return max_sum;
   }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
       

        int n = matrix.size();
        int m = matrix[0].size();

        int max_sum_rectangle = INT_MIN;

        for(int i=0;i<n;i++)
        {
            vector<int>arr(m,0);

            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    arr[k] += matrix[j][k];
                }

               max_sum_rectangle = max(max_sum_rectangle,subarray_sum_not_greater_than_k(arr,k));
            }
        }

        return max_sum_rectangle;
    }
};
