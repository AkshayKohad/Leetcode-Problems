class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>visited(n,0);
        queue<int>q;
        q.push(start);
        visited[start] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(arr[cur] == 0)return true;
            int left = cur-arr[cur];
            int right = cur+arr[cur];
           
            if(left>=0){
                if(!visited[left]){
                    q.push(left);
                    visited[left] = 1;
                }
            }

            if(right<n){
                if(!visited[right]){
                    q.push(right);
                    visited[right] = 1;
                }
            } 
        }

        return false;
    }
};
