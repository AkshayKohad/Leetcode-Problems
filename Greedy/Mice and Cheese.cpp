class Solution {
public:
    
   
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<vector<int>>reward;
        
        int n = reward1.size();
        
        for(int i=0;i<n;i++)
        {
            reward.push_back({reward1[i]-reward2[i],reward1[i],reward2[i]});
        }
        
        sort(reward.begin(),reward.end(),greater<vector<int>>());
        
        int result_reward = 0;
        for(int i=0;i<k;i++)
        {
            result_reward += reward[i][1];
        }
        
        for(int i=k;i<n;i++)
        {
            result_reward += reward[i][2];
        }
        
        return result_reward;
    }
};
