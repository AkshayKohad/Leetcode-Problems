class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>numbers;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                numbers.push_back(grid[i][j]);
            }
        }

        sort(numbers.begin(),numbers.end());
        int sz = numbers.size();
        for(int i=0;i<sz-1;i++){
            int diff = numbers[i+1]-numbers[i];

            if(diff%x != 0)return -1;
        }

        int median = numbers[sz/2];
        int result = 0;

        for(int i=0;i<sz;i++){
            result += abs(numbers[i]-median);
        }

        return result/x;
    }
};


