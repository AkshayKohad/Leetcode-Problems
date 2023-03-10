class Solution {
public:
    
    static bool mycmp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
     sort(points.begin(),points.end(),mycmp);   

     int n = points.size();
     int max_diff = 0;
     for(int i=0;i<n-1;i++)
     {
         max_diff = max(max_diff,points[i+1][0]-points[i][0]);
     }

     return max_diff;
    }
};
