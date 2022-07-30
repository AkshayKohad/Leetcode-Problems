class Solution {
public:
    
    
    // used Monotonic stack to leftmost max and rightmost max and using that I found out contiguous size of values less than particular index at left and right side
    //and then applied dp concept to find out answer 
    
    int solve(int i,vector<int>&arr,int &d,int &n,vector<int>&left_min_size,vector<int>&right_min_size,vector<int>&memo)
    {
        if(i<0 || i>=n)
            return 0;
        
        
        if(memo[i]!=-1)
            return memo[i];
        
        int ans1 = 0;
        for(int j=1;j<=min(d,right_min_size[i]);j++)
        {
            ans1 = max(ans1,1+solve(i+j,arr,d,n,left_min_size,right_min_size,memo));
        }
        
        int ans2 = 0;
        
        for(int j=1;j<=min(d,left_min_size[i]);j++)
        {
            ans2 = max(ans2,1+solve(i-j,arr,d,n,left_min_size,right_min_size,memo));
        }
        
        return memo[i] = max(ans2,ans1);
        
    }
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        
       vector<int>max_right(n);
        vector<int>max_left(n);
        
        stack<int>st;
        
        st.push(0);
        max_left[0] = -1;
        
        for(int i=1;i<n;i++)
        {
            
            while(st.empty()==false && arr[st.top()]<arr[i])
            {
                st.pop();
            }
            
            if(st.empty()==false)
            {
                max_left[i] = st.top();
                
            }
            
            else{
                max_left[i] = -1;
            }
            
            st.push(i);
        }
        
        
        while(st.empty()==false)
            st.pop();
    
        
        
        st.push(n-1);
        max_right[n-1] = n;
        
        for(int i=n-2;i>=0;i--)
        {
            while(st.empty()==false && arr[st.top()]<arr[i])
            {
                st.pop();
            }
            
           if(st.empty()==false)
           {
               max_right[i] = st.top();
           }
            
            else{
                max_right[i] = n;
            }
            
            st.push(i);
        }
        
        
        vector<int>left_min_size(n);
        
        vector<int>right_min_size(n);
        
        for(int i=0;i<n;i++)
        {
            left_min_size[i] = i-max_left[i]-1;
            
            right_min_size[i] = max_right[i]-i-1;
        }
        
        

        
        vector<int>memo(n,-1);
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            res = max(res,1+solve(i,arr,d,n,left_min_size,right_min_size,memo));
        }
        
        return res;
    }
};
