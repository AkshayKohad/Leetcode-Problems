class Solution {
public:
    static bool mycmp(vector<int>first,vector<int>second)
    {
        if(first[0]==second[0])
        {
            return first[1]<second[1];
        }
        
        return first[0]<second[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     
        sort(intervals.begin(),intervals.end(),mycmp);
        
        vector<vector<int>>a;
        
        a.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {
            if(a.back()[1]>=intervals[i][0])
            {
                
            if(a.back()[1]<intervals[i][1])
            {
                vector<int>temp = a.back();
                a.pop_back();
                a.push_back({temp[0],intervals[i][1]});
            }
            
            else{
                vector<int>temp = a.back();
                a.pop_back();
                a.push_back({temp[0],temp[1]});

                }
                
            }
            
            else{
                a.push_back(intervals[i]);
            }
            
        }
        
        return a;
    }
};
