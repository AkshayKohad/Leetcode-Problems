class Solution {
public:
 
    int count_subarray_sum_equal_to_target(vector<int>&arr,int &target)
    {
         int n = arr.size();
         unordered_map<int,int>mp;

         int sum = 0;
         int count = 0;
         for(int i=0;i<n;i++)
         {
             sum += arr[i];

             if(sum==target)
             {
                count++;
             }

             if(mp.find(sum-target)!=mp.end())
             {
                 count += mp[sum-target];
             }

             mp[sum]++;
         }

         return count;
       
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

         int result = 0;

        for(int i=0;i<n;i++)
        {
            vector<int>arr(m,0);

            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    arr[k] += matrix[j][k];
                }
                result += count_subarray_sum_equal_to_target(arr,target);
            }

         
        }
     return result;   
    }
};
