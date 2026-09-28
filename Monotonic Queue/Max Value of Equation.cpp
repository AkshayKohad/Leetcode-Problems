class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        // Trick was |xi - xj| -> xj > xi for j>i then it will be |xi-xj| = xj-xi
        // Maximize yi + yj + |xi-xj| =  yi + yj + xj - xi = (yi-xi) + (yj+xj)
        // we will have 3 monotonic queue -> max_x, min_x and max_diff
        // as we traverse the array we maintain window, x[maxx.front] - x[min_x.front] <= k and 
        // max_diff.front() + y[i] + x[i]  i E (0,n)

        int n = points.size();
        vector<int>x(n);
        vector<int>y(n);
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            x[i] = points[i][0];
            y[i] = points[i][1];
            diff[i] = y[i]-x[i];
        }

        deque<int>minx;
        deque<int>maxx;
        deque<int>max_diff;
        int left = 0;
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            while(minx.empty()==false && x[minx.back()] > x[i])minx.pop_back();
            while(maxx.empty()==false && x[maxx.back()] < x[i])maxx.pop_back();
            
            
            minx.push_back(i);
            maxx.push_back(i);
            

            int maxi_val = x[maxx.front()];
            int mini_val = x[minx.front()];

            while(maxi_val-mini_val>k){
                left = min(maxx.front(),minx.front())+1;
                if(minx.empty()==false && minx.front() < left)minx.pop_front();
                if(maxx.empty()==false && maxx.front() < left)maxx.pop_front();
                if(max_diff.empty()==false && max_diff.front() < left)max_diff.pop_front();

                maxi_val = x[maxx.front()];
                mini_val = x[minx.front()];
            }

            if(max_diff.empty()==false){
                res = max(res, diff[max_diff.front()] + x[i] + y[i]);
            }

            while(max_diff.empty()==false && diff[max_diff.back()] < y[i]-x[i])max_diff.pop_back();
            max_diff.push_back(i);
        }

        return res;
    }
};

