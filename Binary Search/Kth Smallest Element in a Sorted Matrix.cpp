class Solution {
public:
    int countSmallerEqualElementInRow(vector<int>&row,int mid)
   {
       int l=0;
       int h=row.size()-1;
       int ans = 0;
       while(l<=h)
       {
           int m = (l+h)/2;

          
         if(row[m]<=mid)
           {
               l = m + 1;
           }
           else{
               h = m - 1;
           }
       }


       return l;
   }

   int countSmallerElementInRow(vector<int>&row,int mid)
   {
       int l=0;
       int h=row.size()-1;
       int ans = 0;
       while(l<=h)
       {
           int m = (l+h)/2;

          
         if(row[m]<mid)
           {
               l = m + 1;
           }
           else{
               h = m - 1;
           }
       }


       return h;
   }
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        int ans = -1;
        
       // int n = matrix.size();
        
        while(low<=high)
        {
           int mid = (low+high)/2;

           int lower = 0;
           int upper = 0;

           int isSame = 0;
           for(int i=0;i<n;i++)
           {
               
             lower += countSmallerElementInRow(matrix[i],mid);
             upper += countSmallerEqualElementInRow(matrix[i],mid);
           }

           if(lower <= k-1 && upper>k-1)
           {
              ans = mid;
              
              high = mid-1;
           }

           else if(lower>k-1)
           {
              high = mid-1;
           }
           else if(upper<=k-1){
               low = mid+1;
           }

        }

        return ans;
    }
};
