class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>mp;

        for(auto flower : flowers){
            mp[flower[0]]+=1;
            mp[flower[1]+1]-=1;
        }

        int cur_sum = 0;
        for(auto m : mp){
            m.second += cur_sum;
            mp[m.first] = m.second;
            cur_sum = m.second;
        }
        vector<int>result;
        for(int i=0;i<people.size();i++){
            int people_time = people[i];
            if(mp.find(people_time)!=mp.end()){
                result.push_back(mp[people_time]);
            }else{
                auto it = mp.lower_bound(people_time);
                if(it == mp.begin()){
                    result.push_back(0);
                }else{
                    it = prev(it);
                    result.push_back(it->second);
                }
            } 
        }

        return result;
    }
};
