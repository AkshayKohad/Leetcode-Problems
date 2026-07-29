class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int n = rowCosts.size();
        int m = colCosts.size();
        
        int startRow = min(startPos[0],homePos[0]);
        int endRow = max(startPos[0],homePos[0]);

        int startCol = min(startPos[1],homePos[1]);
        int endCol = max(startPos[1],homePos[1]);

        int res_cost = 0;
        for(int i=startRow;i<=endRow;i++){
            res_cost += rowCosts[i];
        }

        for(int j=startCol;j<=endCol;j++){
            res_cost += colCosts[j];
        }
        res_cost -= rowCosts[startPos[0]] + colCosts[startPos[1]];
        return res_cost; 
    }
};
