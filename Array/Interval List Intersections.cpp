class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>a;
     int i=0;
        int j=0;
        
        int n = firstList.size();
        int m = secondList.size();
        while(i<n && j<m)
        {
            vector<int>b;
            int fl0 = firstList[i][0];
            int sl0 = secondList[j][0];
            int sl1 = secondList[j][1];
            int fl1 = firstList[i][1];
            
            if(fl0>sl0 && fl0>sl1)
            {
                j++;
                continue;
            }
            
            else if(sl0>fl0 && sl0>fl1)
            {
                i++;
                continue;
            }
            
            int x = max(fl0,sl0);
            int y = min(fl1,sl1);
            
            a.push_back({x,y});
            
            if(fl1>sl1)
                j++;
            else
                i++;
            
        }
       
    return a;
    }
};
