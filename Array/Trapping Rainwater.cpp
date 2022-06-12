#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    
    long left_max = 0;
    long right_max = 0;
    
    int left = 0;
    int right = n-1;
    
    long res = 0;
    
    while(left<=right)
    {
        if(arr[left]<=arr[right])
        {
            if(arr[left]>=left_max)
            {
                left_max = arr[left];
            }   
            
            else{
                res += left_max-arr[left];
            }
            
            left++;
        }
       
        else{
            if(arr[right]>=right_max)
            {
                right_max = arr[right];
            }
            
            else{
                res +=  right_max - arr[right];
            }
            
            right--;
        }
    }
    
    return res;
    
}
