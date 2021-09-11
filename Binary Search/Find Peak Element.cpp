class Solution {
    public int findPeakElement(int[] arr) {
       int start=0;
        int end=arr.length-1;
        
        
//In the end, both start and end pointers converge to the largest element
// Thus, loop breaking condition

        while(start<end)
        {
            int mid= start+(end-start)/2;
            
            if(arr[mid]>arr[mid+1]) 
                end=mid;        //See
            else start=mid+1;   
        }
        return start; 
    }
}
