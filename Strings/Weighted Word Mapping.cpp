class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        
        for(auto word : words){
            int sum = 0;
            for(auto ch : word){
                sum += weights[ch-'a'];
                cout<<sum<<" ";
            }
            cout<<endl;
            sum = sum%26;
            char a = 'a'+ 25-sum;
            res.push_back(a);
        }

        return res;
    }
};
