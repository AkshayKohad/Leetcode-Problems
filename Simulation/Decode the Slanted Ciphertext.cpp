class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string result = "";
        int n = encodedText.length();
        int cols = n/rows;
    
        for(int i=0;i<cols;i++){
            int ind = i;

            while(ind<n){
                result.push_back(encodedText[ind]);
                ind += cols+1;
            }
        }
        while(result.size()>0 && result.back()==' '){
            result.pop_back();
        }
        return result;
    }
};
