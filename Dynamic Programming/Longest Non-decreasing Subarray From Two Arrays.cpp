class Solution {
public:

    int solve(vector<int>&nums1,vector<int>&nums2,int &n,int i,int choice,vector<vector<int>>&memo)
    {
         if(i==n) return 0;
         
         if(memo[i][choice]!=-1)
         return memo[i][choice];

        int result = 0;

         if(choice == 0)
         {
             int res = solve(nums1,nums2,n,i+1,0,memo);
             int res1 = 1 + solve(nums1,nums2,n,i+1,1,memo);
             int res2 = 1 + solve(nums1,nums2,n,i+1,2,memo);

            result = max({result,res1,res2,res});
         }

         else if(choice == 1)
         {
             int res1 = 0;
             int res2 = 0;

            if(nums1[i-1]<=nums1[i])
            {
                res1 = 1 + solve(nums1,nums2,n,i+1,1,memo); 
            }

            if(nums1[i-1]<=nums2[i])
            {
                res2 = 1 + solve(nums1,nums2,n,i+1,2,memo);
            }

            result = max({result,res1,res2});
         }

         

         else if(choice==2)
         {
            int res1 = 0;
            int res2 = 0;

            if(nums2[i-1]<=nums1[i])
            {
                res1 = 1 + solve(nums1,nums2,n,i+1,1,memo); 
            }

            if(nums2[i-1]<=nums2[i])
            {
                res2 = 1 + solve(nums1,nums2,n,i+1,2,memo);
            }

            result = max({result,res1,res2});
         }

         return memo[i][choice] = result;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        

        int n = nums1.size();
        
        vector<vector<int>>memo(n+1,vector<int>(3,-1));
        int choice = 0;
       return solve(nums1,nums2,n,0,choice,memo);
    }
};
