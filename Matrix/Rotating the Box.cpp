class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for(int i=0;i<n;i++){
            int cnt_gaps = 0;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j] == '.')cnt_gaps++;
                else if(boxGrid[i][j] == '*'){
                    cnt_gaps = 0;
                }else{
                    if(cnt_gaps > 0){
                        boxGrid[i][j+cnt_gaps] = '#';
                        boxGrid[i][j] = '.';
                    }
                    
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<boxGrid[i][j]<<" ";
            }
            cout<<endl;
        }

        vector<vector<char>> result(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        return result;
    }
};
