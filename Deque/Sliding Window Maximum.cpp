

 // } Driver Code Ends
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> arr, int k) {
        // your code here
        
      int n = arr.size();
        vector<int>ans;
        deque<int>dq;
        
        for(int i=0;i<n;i++)
        {
            if(dq.empty()==true)
            {
                dq.push_back(i);
            }
            
            else{
                while(dq.empty()==false && dq.front()<=i-k)
                dq.pop_front();
                
                
                while(dq.empty()==false && arr[dq.back()]<arr[i])
                dq.pop_back();
                
                dq.push_back(i);
                
            }
            
            
            if(i>=k-1)
            {
                ans.push_back(arr[dq.front()]);
            }
        }
        
        return ans;
    }
};

