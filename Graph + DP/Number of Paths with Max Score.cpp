class Solution {
public:
    #define mod 1000000007
    vector<pair<int,int>>directions = {{-1,0},{0,-1},{-1,-1}};
    vector<int> pathsWithMaxScore(vector<string>& board) {
     int n = board.size();
     int m = board[0].size();

     vector<vector<int>>res_max(n,vector<int>(m,0));
     vector<vector<int>>res_ways(n,vector<int>(m,0));

     res_max[0][0] = 0;
     res_ways[0][0] = 1;

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)continue;
            if(board[i][j] == 'X')continue;
            for(auto dir : directions){
                int x = i+dir.first;
                int y = j+dir.second;

                if(x<0 || y<0 || board[x][y] == 'X' || res_ways[x][y] == 0)continue;

                int val = board[x][y] - '0';
                if(x == 0 && y == 0)val = 0;
                if(res_max[i][j] < res_max[x][y] + val){
                    res_max[i][j] = res_max[x][y] + val;
                    res_ways[i][j] = res_ways[x][y];
                }else if(res_max[i][j] == res_max[x][y] + val){
                    res_ways[i][j] = (res_ways[x][y] + res_ways[i][j])%mod; 
                }else{
                    continue;
                }
            }
        }
     }

     return {res_max[n-1][m-1], res_ways[n-1][m-1]};   
    }
};
