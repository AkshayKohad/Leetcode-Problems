class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        if(m.size()==0)
            return 0;
        int i=0;
        int j=m[i].size()-1;
        
        while(i<m.size() && j>=0)
        {
            if(m[i][j]>t)
                j--;
            else if(m[i][j]<t)
                i++;
            else if(m[i][j]==t)
                return true;
        }
        return false;
    }
};
