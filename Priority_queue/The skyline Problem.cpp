class Solution {
public:
    
    static bool mycmp(pair<int,int>f,pair<int,int>s)
    {
        if(f.first==s.first)
            return f.second > s.second;
        
        return f.first < s.first;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int,int>>points;
        
        int prev_height = 0;
        int curr_height = 0;
        
        
        multiset<int>a;
        a.insert(0);
        
        for(int i=0;i<buildings.size();i++)
        {
            points.push_back({buildings[i][0],buildings[i][2]});
            points.push_back({buildings[i][1],-buildings[i][2]});
        }
        
        
        sort(points.begin(),points.end(),mycmp);
        
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++)
        {
            
            if(points[i].second>0)
            {
                a.insert(points[i].second);
            }
            
            else{
                a.erase(a.find(-points[i].second));
            }
            
            curr_height = *a.rbegin();
            
            if(curr_height!=prev_height)
            {
                ans.push_back({points[i].first,curr_height});
                
                prev_height = curr_height;
            }
        }
         
        return ans;
    }
};
