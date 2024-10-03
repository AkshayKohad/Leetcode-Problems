#define ll long long

class Solution {
public:
    ll solve(string word, int k){

        unordered_map<char,int>vowels;
        int cnt_consonants = 0;

        int i=0;
        int j=0;

        int n = word.length();
        
        long long result = 0;

        while(j<n){
          
          if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u'){
            vowels[word[j]]++;
          }
          else{
            cnt_consonants++;
          }

          while(i<=j && cnt_consonants>=k && vowels.size()==5){
              result += word.size()-j;

              if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                    vowels[word[i]]--;

                    if(vowels[word[i]]==0)vowels.erase(word[i]);
              }
              else{
                cnt_consonants--;
              }

              i++;
              }

              j++;
          }

          return result;
        }
    
    
    long long countOfSubstrings(string word, int k) {
        
        return solve(word,k) - solve(word,k+1);
    }
};
