class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int i=0;
        int n = colors.size();
        
        int res = 0;
        while(i<n)
        {
            priority_queue<int,vector<int>,greater<int>>pq;
             int j = i;   
            while(j<n && colors[i] == colors[j])
            {
                pq.push(neededTime[j]);
                j++;
            }
            i = j;
            
            while(pq.size()>1)
            {
                res += pq.top();
                pq.pop();
            }
        }
        
        return res;
    }
};
