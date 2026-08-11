class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        vector<int>suffix(n,0);
        int m = word2.length();
        int suf = 0;
        int i = n-1;
        int j = m-1;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                suf++;
                suffix[i] = suf;
                i--;
                j--;
            }else{
                suffix[i] = suf;
                i--;
            }   
        }

        while(i>=0){
            suffix[i] = suf;
            i--;
        }

        i = 0;
        j = 0;
        int chance = 1;
        vector<int>result;
        while(j<m && i<n){
            if(word1[i] == word2[j]){
                result.push_back(i);
                i++;
                j++;
            }else{
                if(chance){
                    if(i<n-1){
                        if(suffix[i+1] >= m-j-1){
                            result.push_back(i);
                            i++;
                            j++;
                            chance = 0;
                        }else{
                            i++;
                        }
                    }else{
                        result.push_back(i);
                        i++;
                        j++;
                        chance = 0;
                    }
                }else{
                    i++;
                }
            }
        }

        if(j==m)return result;
        return {};
    }
};
