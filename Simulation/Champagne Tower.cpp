class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double>>glasses(101,vector<double>(101,0.0));
        glasses[0][0] = (double) poured;
        for(int r = 0;r <= query_row; r++){
            for(int c = 0;c <= r; c++){
                double q = (glasses[r][c] - 1.0)/2.0;
                if (q > 0){
                    glasses[r+1][c] += q;
                    glasses[r+1][c+1] += q;
                }
            }
        }

        return min(1.0,glasses[query_row][query_glass]);
    }
};
