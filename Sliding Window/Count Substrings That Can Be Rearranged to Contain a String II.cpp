#define ll long long

class Solution {
public:
  
    long long validSubstringCount(string word1, string word2) {
        
        unordered_map<char,int>mp;

        for(auto k:word2){
            mp[k]++;
        }

        unordered_map<char,int>window;
        ll cnt=0;
        ll i=0;
        ll j=0;
        
        ll n = word1.length();
        ll m = word2.length();

        while(j<n && cnt<m)
        {
           if(mp.find(word1[j])!=mp.end()){
               if(mp[word1[j]]>window[word1[j]]){
                  cnt++;
               }     
           }

           window[word1[j]]++;
           j++;
        }
        
        if(cnt<m)return 0;

        while(i<j){
            if(mp.find(word1[i])!=mp.end()){
               if(mp[word1[i]]==window[word1[i]]){
                  break;
               }     
           }
           window[word1[i]]--;
           i++;
        }

        ll res=1+i;

        while(j<n)
        {
           window[word1[j]]++;
           j++;
           while(i<j){
            if(mp.find(word1[i])!=mp.end()){
               if(mp[word1[i]]==window[word1[i]]){
                  break;
               }     
           }
           window[word1[i]]--;
           i++;
          }

          res += i+1;
        }

        return res;
    }
};
