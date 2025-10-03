class Node{
    public:
    
    Node* characters[26];
    bool isEnd;
    Node(){
        for(int i=0;i<26;i++){
            characters[i] = NULL;
        }
        isEnd = false;
    }
};


class MagicDictionary {
public:

    Node*root;
    MagicDictionary() {
        root = new Node();
    }
    
    void insert(Node*root,string s){
        Node*cur = root;
        for(int i=0;i<s.length();i++){
            if(cur->characters[s[i]-'a'] == NULL){
                cur->characters[s[i]-'a'] = new Node();
            }

            cur = cur->characters[s[i]-'a'];
        }

        cur->isEnd = true;
    }

    void buildDict(vector<string> dictionary) {
        
        for(int i=0;i<dictionary.size();i++){
            insert(root,dictionary[i]);
        }
        
    }
    
    bool search_result(string &word,bool isChanged,int i,Node*root){
        if(i==word.length()){
            if(isChanged && root->isEnd)return true;
            return false;
        }

        bool res = false;
        int ch = word[i]-'a';
        for(int j=0;j<26;j++){
            if(root->characters[j]==NULL)continue;

            if(ch == j){
                res = res | search_result(word,isChanged,i+1,root->characters[j]);
                if(res)return true;
            }else{
                if(isChanged == false){
                    res = res | search_result(word,true,i+1,root->characters[j]);
                    if(res) return true;
                }
            }
        }

        return false;
    }

    bool search(string searchWord) {
        bool isChanged = false;
        return search_result(searchWord,isChanged,0,root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
