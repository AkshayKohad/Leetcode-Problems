constexpr int INF = 1000000000;
class Solution {
public:

    class Trie{

     public:
     
     char ch;
     bool isend;
     Trie*character[26];
     Trie(){
         for(int i=0;i<26;i++)
        character[i]=NULL;
       
        bool isend = false;
     }
     
    };

    void insert(Trie*root,string s) {
         int n = s.length();

         for(int i=0;i<n;i++){
            int ch = s[i]-'a';
            
            if(root->character[ch]==NULL)
            {
                root->character[ch] = new Trie();
            }

            root = root->character[ch];
         }

         root->isend = true;

    }

    int minValidStrings(vector<string>& words, string target) {

          Trie*root = new Trie();

          for(int i=0;i<words.size();i++){
             insert(root,words[i]);
           } 

           int n = target.length();

           vector<int>dp(n+1,INF);
           dp[n]=0;

           for(int i=n-1;i>=0;i--){
            Trie*cur = root;
            int cur_ind = i-1;
           
            while((cur_ind+1<n) && (cur->character[target[cur_ind+1]-'a']!=NULL)){
                 cur = cur->character[target[cur_ind+1]-'a'];
                 cur_ind++;
                 
                 dp[i] = min(dp[i],dp[cur_ind+1]+1);
            }
           }

           cout<<dp[0]<<"\n";

           return dp[0] == INF ? -1:dp[0];

    }
};
