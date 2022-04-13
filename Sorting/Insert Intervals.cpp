class Solution {
public:
    
    static bool mycmp(vector<int>f,vector<int>s)
    {
         if(f[0] == s[0])
             return f[1] < s[1];
        
        return f[0] < s[0];
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        intervals.push_back(newInterval);
        
        if(n==0)
            return intervals;
        
        sort(intervals.begin(),intervals.end(),mycmp);
        
        vector<vector<int>>ans;
        
        ans.push_back(intervals[0]);
        
        n = intervals.size();
        for(int i=1;i<n;i++)
        {
            
            // complete overlap
            if(ans.back()[0]<= intervals[i][0] && ans.back()[1] >= intervals[i][1])
            {
                continue;
            }
                
                
            // partial overlap
            else if(ans.back()[1] >= intervals[i][0] )
             {
                 int x = ans.back()[0];
                 int y = intervals[i][1];
                 
                 ans.pop_back();
                 
                 ans.push_back({x,y});
               }
                
                
            // no overlap 
            else if(ans.back()[1]< intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
        
    }
};
