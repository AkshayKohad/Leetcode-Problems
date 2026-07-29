class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        set<pair<int,int>>st;
        for(auto point : points){
            st.insert({point[0],point[1]});
        }

        sort(points.begin(),points.end());
        int max_area = -1;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int diff_x = points[i][0]-points[j][0];
                int diff_y = points[i][1]-points[j][1];

                if(diff_x == 0 || diff_y == 0)continue;

                if(st.find({points[i][0],points[j][1]}) == st.end() || st.find({points[j][0],points[i][1]}) == st.end())continue;

                int max_x = max(points[i][0],points[j][0]);
                int min_x = min(points[i][0],points[j][0]);
                int max_y = max(points[i][1],points[j][1]);
                int min_y = min(points[i][1],points[j][1]);
                bool isPossible = true;
                for(int k=0;k<points.size();k++){
                    if (points[k] == points[j] || points[k] == points[i] || (points[k][0] == points[i][0] && points[k][1] == points[j][1]) || (points[k][0] == points[j][0] && points[k][1] == points[i][1]))continue;

                    if(points[k][0] >= min_x && points[k][0] <= max_x && points[k][1] >= min_y && points[k][1] <= max_y){
                        isPossible = false;
                        break;
                    }
                }

                if(isPossible){
                    max_area = max(max_area,abs(diff_x*diff_y));
                }
            }
        }

        return max_area;
    }
};
