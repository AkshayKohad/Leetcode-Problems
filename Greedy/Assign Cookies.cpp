class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ind_g = 0;
        int ind_s = 0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(ind_g < g.size() && ind_s < s.size()){
            if(g[ind_g]<=s[ind_s]){
                ind_g++;
            }
            ind_s++;
        }

        return ind_g;
    }
};
