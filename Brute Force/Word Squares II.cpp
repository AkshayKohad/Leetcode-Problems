class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>>result;
        sort(words.begin(),words.end());
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && words[i][0] == words[j][0]){
                    for(int k=0;k<n;k++){
                        if(i!=k && j!=k && words[i][3] == words[k][0]){
                            for(int l=0;l<n;l++){
                                if(l!=k && l!=i && l!=j && words[l][0] == words[j][3] && words[l][3] == words[k][3]){
                                    result.push_back({words[i],words[j],words[k],words[l]});
                                }
                            }
                        }
                    }
                }
            }
        }

        sort(result.begin(),result.end());
        return result;

    }
};
