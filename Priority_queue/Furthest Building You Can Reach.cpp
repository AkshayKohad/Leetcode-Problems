class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
       int n = heights.size();
      
      int remaining_bricks = bricks;
        priority_queue<int,vector<int>,greater<int>>min_heap;

        for(int i=1;i<n;i++)
        {
            if(heights[i]>heights[i-1])
            {
                if(min_heap.size()<ladders)
                {
                    min_heap.push(heights[i]-heights[i-1]);
                }
                else{
                    int diff = heights[i]-heights[i-1];

                   min_heap.push(diff);
                    if(remaining_bricks >= min_heap.top())
                    {
                        remaining_bricks = remaining_bricks-min_heap.top();
                        min_heap.pop();
                    }
                    else{
                        return i-1;
                    }
                }
            }
        }

        return n-1;


    }
};
