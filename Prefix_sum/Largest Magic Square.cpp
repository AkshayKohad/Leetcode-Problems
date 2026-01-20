class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>row(n,vector<int>(m+1,0));
        vector<vector<int>>col(n+1,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                row[i][j] = row[i][j-1] + grid[i][j-1];
            }
        }

        for(int j=0;j<m;j++){
            for(int i=1;i<=n;i++){
                col[i][j] =  col[i-1][j] + grid[i-1][j];
            }
        }

        int result = 1;

        for(int len=2;len<=min(n,m);len++){
            for(int i=0;i+len<=n;i++){
                for(int j=0;j+len<=m;j++){
                    int r_sum = row[i][j+len] - row[i][j];
                    bool isSame = true;

                    for(int l=i+1;l<i+len;l++){
                        int temp_sum = row[l][j+len] - row[l][j];
                        if(temp_sum != r_sum){
                            isSame = false;
                            break;
                        }
                    }

                    if(!isSame)continue;

                    int c_sum = col[i+len][j]-col[i][j];
                    isSame = true;

                    for(int l=j+1;l<j+len;l++){
                        int temp_sum = col[i+len][l]-col[i][l];
                        if(temp_sum != c_sum){
                            isSame = false;
                            break;
                        }
                    }

                    if(!isSame)continue;

                    int diag1 = 0;

                    int x=i;
                    int y=j;

                    while(x<i+len && y<j+len){
                        diag1 += grid[x][y];
                        x++;
                        y++;
                    }

                    int diag2 = 0;
                    x=i+len-1;
                    y=j;

                    while(x>=i && y<j+len){
                        diag2 += grid[x][y];
                        x--;
                        y++;
                    }

                    if(r_sum == c_sum && r_sum == diag1 && r_sum == diag2){
                        result = len;
                    }

                }
            }
        }

        return result;
    }
};
