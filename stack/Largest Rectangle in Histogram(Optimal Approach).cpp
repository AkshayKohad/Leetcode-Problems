#include <bits/stdc++.h> 

int largestRectangle(vector < int > & h) {
   // Write your code here.
     
     stack<int>st;
    
    int n = h.size();
     int max_area = 0;
     for(int i=0;i<n;i++)
     {
         if( st.empty()==true || h[i]>=h[st.top()])
         {
               st.push(i);
         }
         
         else{
             int j = i;
             
             while(st.empty()==false && h[j]<h[st.top()])
             {
             int k = st.top();
             
             st.pop();
             
             if(st.empty()==true)
             {
                 max_area = max(max_area,j*h[k]);
             }
             
             else{
                 max_area = max(max_area,(j-st.top()-1)*h[k]);
             }
                 
               
                 
             }
             
               st.push(j);
         }
     }
     
     int i = n;
     
     
      while(st.empty()==false)
             {
             int k = st.top();
             
             st.pop();
             
             if(st.empty()==true)
             {
                 max_area = max(max_area,i*h[k]);
             }
             
             else{
                 max_area = max(max_area,(i-st.top()-1)*h[k]);
             }
                 
               
                 
             }
     
     return max_area;
            
         
 }
