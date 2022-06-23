#include <bits/stdc++.h>

vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    
    
   // nearest left smaller to element 
   vector<int>left(n);
   stack<int>st_left;
    
    for(int i=0;i<n;i++)
    {
        while(st_left.empty()==false &&  a[st_left.top()]>=a[i])
        {
            st_left.pop();
        }
        
        if(st_left.empty()==true)
        {
            left[i] = -1;
        }
        
        else{
            left[i] = st_left.top();
        }
        
        st_left.push(i);
    }
    
    
    // nearest right smaller to element 

    vector<int>right(n);
    stack<int>st_right;
    
    
     for(int i=n-1;i>=0;i--)
     {
         while(st_right.empty()==false && a[st_right.top()]>=a[i])
         {
             st_right.pop();
         }
         
         if(st_right.empty()==true)
         {
             right[i] = n;
         }
         
         else{
             right[i] = st_right.top();
         }
         
         st_right.push(i);
     }
    
    // It will give us resulting window size each element can
    //have by doing right_index-left_index-1
    vector<int>res_window(n);
    
    for(int i=0;i<n;i++)
    {
        res_window[i] = right[i]-left[i]-1;
        
    }
    
    
    // res will be resulting answer we will be using res_window 
    //and match it's value with res's index as res's index 
    //indicates window size and res_window is having value as 
    //window size
    
    
    vector<int>res(n,INT_MIN);
    
    for(int i=0;i<n;i++)
    {
        int window = res_window[i];
        int val = a[i];
        
        res[window-1] = max(res[window-1],val);
        
        
    }
    
    
    for(int i = n-2;i>=0;i--)
    {
        res[i] = max(res[i+1],res[i]);
    }
    
    return res;
}
