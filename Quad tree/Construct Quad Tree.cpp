/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

   bool isSame(vector<vector<int>>&grid,int x,int y,int &n)
   {
       int val = grid[x][y];

       for(int i=x;i<x+n;i++)
       {
           for(int j=y;j<y+n;j++)
           {
               if(grid[i][j]!=val)
                  return false;
           }
       }

       return true;
   }
   
   Node* solve(vector<vector<int>>&grid,int i,int j,int n)
   {
       if(isSame(grid,i,j,n))
       return new Node(grid[i][j],true);

       Node*cur = new Node(2,false);

       cur->topLeft = solve(grid,i,j,n/2);
       cur->topRight = solve(grid,i,j+n/2,n/2);
       cur->bottomLeft = solve(grid,i+n/2,j,n/2);
       cur->bottomRight = solve(grid,i+n/2,j+n/2,n/2);

       return cur;
   }


    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return solve(grid,0,0,n);
    }
};
