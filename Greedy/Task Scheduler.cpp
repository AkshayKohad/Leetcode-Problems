class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(auto task : tasks){
            int ch = task - 'A';
            freq[ch]++;
        }

        sort(freq.begin(),freq.end(),greater<int>());
        
        int maxGap = freq[0] - 1;
        int available_slots = maxGap*n;

        for(int i=1;i<26;i++){
            available_slots -= min(maxGap,freq[i]);
        }

        available_slots = max(0,available_slots);

        return tasks.size() + available_slots;
    }
};
