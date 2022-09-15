class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        multiset<int> chargeTimeSet;
        long long runningCostSum = 0;
        
        int l = 0;
        int maxLength = 0;
        
        for (int r = 0; r < chargeTimes.size(); r++) {
            chargeTimeSet.insert(chargeTimes[r]);
            runningCostSum += runningCosts[r];
            
            int maxChargeTime = *(chargeTimeSet.rbegin());
            
            long long v = maxChargeTime + (long long)(r - l + 1) * runningCostSum;
            while (v > budget && l <= r) {
                runningCostSum -= runningCosts[l];
                chargeTimeSet.erase(chargeTimeSet.find(chargeTimes[l]));

                l++;
                
                if (chargeTimeSet.size() > 0) {
                    maxChargeTime = *(chargeTimeSet.rbegin());
                }
                
                v = maxChargeTime + (r - l + 1) * runningCostSum;
            }
            
            if (l <= r) {
                maxLength = max(maxLength, r - l + 1);
            }
        }
        
        return maxLength;
    }
};
