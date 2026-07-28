class Solution {
public:
    void solve(string curStop,unordered_map<string,vector<string>>&flightMap,vector<string>&result){
        
       
        vector<string>&destinations = flightMap[curStop];
        while(!destinations.empty()){
            string nextStop = destinations.back();
            destinations.pop_back();
            solve(nextStop,flightMap,result);
        }
        result.push_back(curStop);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>flightMap;

        for(auto ticket : tickets){
            flightMap[ticket[0]].push_back(ticket[1]);
        }

        for(auto& Map : flightMap){
            sort(Map.second.rbegin(),Map.second.rend());
        }

        vector<string>result;
        solve("JFK",flightMap,result);

        reverse(result.begin(),result.end());
        return result;
    }
};
