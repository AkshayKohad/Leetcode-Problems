class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 1;
    int val = arr[0];
    int n = arr.size();
    for(int i=1;i<n;i++)
    {
       if(arr[i]==val)
       {
           count++;
       }
        
       else{
           if(count==1)
           {
               val = arr[i];
           }
           
           else{
               count--;
           }
       } 
    }
    
    count = 0;
    for(int i=0;i<n;i++)
    {
        if(val == arr[i])
            count++;
    }
    if(count>n/2)
    return val;
    
    return -1;
    }
};
