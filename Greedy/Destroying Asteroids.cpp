class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long res_mass = mass;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(res_mass >= asteroids[i]){
                res_mass += asteroids[i];
            }else{
                return false;
            }
        }

        return true;
    }
};
