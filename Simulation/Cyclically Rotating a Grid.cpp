class Solution {
public:
    void traverse_bottom(int s,int e,int j,vector<int>&res,vector<vector<int>>&grid){
        for(int i=s;i<=e;i++){
            res.push_back(grid[i][j]);
        }
    }

    void traverse_top(int s,int e,int j,vector<int>&res,vector<vector<int>>&grid){
        for(int i=s;i>=e;i--){
            res.push_back(grid[i][j]);
        }
    }

    void traverse_right(int s,int e,int j,vector<int>&res,vector<vector<int>>&grid){
        for(int i=s;i<=e;i++){
            res.push_back(grid[j][i]);
        }
    }

    void traverse_left(int s,int e,int j,vector<int>&res,vector<vector<int>>&grid){
        for(int i=s;i>=e;i--){
            res.push_back(grid[j][i]);
        }
    }

    void rotate(vector<int>&res,int k){
        int n = res.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            int ind = (i+k)%n;
            temp[ind] = res[i];
        }

        for(int i=0;i<n;i++){
            res[i] = temp[i];
        }
    }

    void print_bottom(int s,int e,int j,vector<int>&res,vector<vector<int>>&result,int &index){
        for(int i=s;i<=e;i++){
            result[i][j] = res[index];
            index++;
        }
    }

    void print_top(int s,int e,int j,vector<int>&res,vector<vector<int>>&result,int &index){
        for(int i=s;i>=e;i--){
            result[i][j] = res[index];
            index++;
        }
    }

    void print_right(int s,int e,int j,vector<int>&res,vector<vector<int>>&result,int &index){
        for(int i=s;i<=e;i++){
            result[j][i] = res[index];
            index++;
        }
    }

    void print_left(int s,int e,int j,vector<int>&res,vector<vector<int>>&result,int &index){
        for(int i=s;i>=e;i--){
            result[j][i] = res[index];
            index++;
        }
    }


    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>result(n,vector<int>(m));

        int start_row = 0;
        int end_row = n-1;
        int start_col = 0;
        int end_col = m-1;

        while(start_row<end_row && start_col<end_col){
            vector<int>res;
            traverse_bottom(start_row,end_row,start_col,res,grid);
            traverse_right(start_col+1,end_col,end_row,res,grid);
            traverse_top(end_row-1,start_row,end_col,res,grid);
            traverse_left(end_col-1,start_col+1,start_row,res,grid);

            rotate(res,k);
            int index = 0;
            print_bottom(start_row,end_row,start_col,res,result,index);
            print_right(start_col+1,end_col,end_row,res,result,index);
            print_top(end_row-1,start_row,end_col,res,result,index);
            print_left(end_col-1,start_col+1,start_row,res,result,index);

            start_row++;
            end_row--;
            start_col++;
            end_col--;
        }

        return result;
    }
};
