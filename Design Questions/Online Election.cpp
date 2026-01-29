#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> leader;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;

        unordered_map<int,int> cnt;
        int curLeader = -1;
        int curMax = 0;

        for (int i = 0; i < persons.size(); i++) {
            cnt[persons[i]]++;

            
            if (cnt[persons[i]] >= curMax) {
                curMax = cnt[persons[i]];
                curLeader = persons[i];
            }

            leader.push_back(curLeader);
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leader[idx];
    }
};
