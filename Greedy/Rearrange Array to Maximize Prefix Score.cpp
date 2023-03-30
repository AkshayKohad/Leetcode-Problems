class Solution {
public:
    int maxScore(vector<int>& nums) {

     vector<int>positive;
     vector<int>zero;
     vector<int>negative;

     int n = nums.size();

     for(int i=0;i<n;i++)
     {
         if(nums[i]>0)
         {
             positive.push_back(nums[i]);
         }
         else if(nums[i]==0)
         {
             zero.push_back(nums[i]);
         }

         else{
             negative.push_back(nums[i]);
         }
     }   

     sort(negative.begin(),negative.end(),greater<int>());

     long long  prefix_sum = 0;

     int result = 0;

     for(int i=0;i<positive.size();i++)
     {
         prefix_sum += positive[i];

         if(prefix_sum>0)
         {
           result++;
         }
     }

     for(int i=0;i<zero.size();i++)
     {
         if(prefix_sum>0)
         result++;
     }

     for(int i=0;i<negative.size();i++)
     {
         prefix_sum += negative[i];

         if(prefix_sum>0)
         result++;
     }

     return result;
    }
};
