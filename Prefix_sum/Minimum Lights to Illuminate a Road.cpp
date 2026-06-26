class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            int power = lights[i];
            if(lights[i]==0)continue;
            int left = max(0,i-power);
            int right = min(n-1,i+power);

            prefix[left] += 1;
            prefix[right+1] -= 1;
        }

        for(int i=1;i<=n;i++){
            prefix[i] += prefix[i-1];
        }
        
        int res = 0;
        int i=0;
        while(i<n){
            if(prefix[i]!=0){
                i++;
                continue;
            }

            int cnt = 0;
            while(i<n && prefix[i]==0){
                cnt++;
                i++;
            }
            res += cnt/3;
            res += cnt%3 == 0 ? 0:1;
        }
        return res;
    }
};
