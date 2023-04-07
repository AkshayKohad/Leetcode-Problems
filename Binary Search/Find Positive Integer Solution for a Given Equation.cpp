/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    void checkx(int y,vector<vector<int>>&result,int target,CustomFunction& customfunction)
    {
        int lx = 1;
        int rx = 1000;

        while(lx<=rx)
        {
            int midx = (lx+rx)/2;

            int val = customfunction.f(midx,y);

            if(val==target)
            {
                result.push_back({midx,y});
                return;
            }
            else if(val<target)
            {
                lx = midx+1;
            }
            else{
                rx = midx-1;
            }
        }
    }
    
    
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>result;
        for(int i=1;i<=1000;i++)
        {
            checkx(i,result,z,customfunction);
         
        }

        return result;
    }
};
