class Trie{
    private:
        Trie*characters[26];
        bool isEnd = false;
    public:

        Trie(){
            for(int i=0;i<26;i++){
                characters[i] = NULL;
            }
        }

        ~Trie(){
            for(int i=0;i<26;i++){
                delete characters[i];
            }
        }

        void insert(string word){
            Trie*cur = this;
            for(int i=0;i<word.length();i++){
                int ch = word[i]-'a';

                if(cur->characters[ch]==NULL){
                    cur->characters[ch] = new Trie();
                }

                cur = cur->characters[ch];
            }
            cur->isEnd = true;
        }

        private:
           bool dfs(int i,string word,int max_edit_limit){
                if(i==word.length())return isEnd;

                int char_ch = word[i]-'a';
                for(int j=0;j<26;j++){
                    if(characters[j]==NULL)continue;

                    if(char_ch==j){
                        if(characters[j]->dfs(i+1,word,max_edit_limit))return true;
                    }else if(max_edit_limit>0){
                        if(characters[j]->dfs(i+1,word,max_edit_limit-1))return true;
                    }
                }
                return false;
           }

        public:
            bool find(string word,int max_edit_limit){
                return this->dfs(0,word,max_edit_limit);
            }

};


class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        Trie*root = new Trie();
        vector<string>result;
        for(auto word : dictionary){
            root->insert(word);
        }

        for(auto query : queries){
           
            if(root->find(query,2)){
                result.push_back(query);
            }

        }

        return result;

    }
};
