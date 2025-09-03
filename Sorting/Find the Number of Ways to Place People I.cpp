class Solution {
public:


    static bool mycmp(vector<int>&f,vector<int>&s){
        if(f[0]==s[0]){
            return f[1] > s[1]; 
        }

        return f[0]<s[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        sort(points.begin(),points.end(),mycmp);
        int result=0;

        for(int i=0;i<n;i++){
            int maxi = -1;

            for(int j=i+1;j<n;j++){
                if(points[i][1] < points[j][1])continue;

                if(maxi < points[j][1]){
                    maxi = points[j][1];
                    result++;
                }

            }
        }
        
        return result;
    }
};
