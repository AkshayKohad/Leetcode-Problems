class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>a;
        int n = heights.size();
        for(int i=0;i<n;i++)
        {
            a.push_back(heights[i]);
        }
        
        stack<int>s;
        
        //left side
        for(int i=0;i<n;i++)
        {
            if(s.empty()==true)
            {
                s.push(i);
                continue;
            }
            
            
            while(s.empty()==false && heights[s.top()]>=heights[i])
            {
               
                 s.pop();
            }
            
          
            if(s.empty()==true)
            {
                a[i] += heights[i]*(i);
            }
            else
            {
            a[i] += heights[i]*(i-s.top()-1);
            }
            s.push(i);
        }
        
       stack<int>s1;
        //right side
        
         for(int i=n-1;i>=0;i--)
        {
            if(s1.empty()==true)
            {
                s1.push(i);
                continue;
            }
            
            
            while(s1.empty()==false && heights[s1.top()]>=heights[i])
            {
               
                 s1.pop();
            }
             if(s1.empty()==true)
             {
                 a[i] += heights[i]*(n-1-i);
             }
             
             else{
                 a[i] += heights[i]*(s1.top()-i-1);
             }
            s1.push(i);
            
        }
        
        int res = a[0];
        for(int i=0;i<n;i++)
        {
            res = max(a[i],res);
            //cout<<a[i]<<" ";
        }
       
        
        return res;
        
    }
};
