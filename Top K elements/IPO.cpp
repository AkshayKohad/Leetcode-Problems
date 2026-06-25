class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {
        
        int n = profits.size();

        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfit;
        int i = 0;

        while (k--) {
            // Add all projects we can currently afford
            while (i < n && projects[i].first <= w) {
                maxProfit.push(projects[i].second);
                i++;
            }

            // No affordable project left
            if (maxProfit.empty()) {
                break;
            }

            // Choose the most profitable one
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};
