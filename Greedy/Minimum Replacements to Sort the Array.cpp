class Solution {
public:  
    
    
//     long long  minimum(int val,long long mini)
//     {
//         if(val%2==0)
//         {
            
//         }
//     }
    long long minimumReplacement(vector<int>& nums) {
        
        int n = nums.size();
        
        int mini = nums[n-1];
        
        long long res = 0;
        for(int i=n-2;i>=0;i--)
        {
            if(mini>=nums[i])
            {
                mini = nums[i];
                
            }
            
            else{
                
                if(nums[i]%mini == 0)
                {
                    
                    // equally dividing it into previous mini
                      long long  ans =  nums[i]/mini;
                    
                    //number of splits required
                       ans = ans - 1;
                    res += ans;
                }
                
                else{
                    
                    // now we find divisor completely divided by mini
                    long long ans = nums[i]/mini;
                    
                    // since there is remainder as well so number of splits will be ans not ans-1
                    
                    res += ans;
                    
                    
               //int val =nums[i] - mini*(ans-1);
                    
                    
                    // now to get maximum of minimum of spliting possiblities we divide nums[i] by ans+1 that states we are trying to
                    // spilt the nums[i] equally including remainder part it will give maximum result
                    
                    mini = nums[i]/(ans+1);
                    
                    
                    
                }
            }
        }
        
        return res;
    }
};
