class WordDictionary {
public:
    class Trie{
        public:
        Trie*characters[26];
        bool isEnd;
        
        Trie()
        {
            for(int i=0;i<26;i++)
            {
                characters[i] = NULL;
            }
            
            isEnd = false;
        }
        
    };
    
    
    Trie*root;
    
    WordDictionary() {
        root = new Trie;
    }
    
    void addWord(string word) {
        
        Trie*cur = root;
        
        for(int i=0;i<word.length();i++)
        {
            int k = word[i]-'a';
            if(cur->characters[k]==NULL)
            {
                cur->characters[k] = new Trie;
                
            }
            
            cur = cur->characters[k];
        }
        
        cur->isEnd  = true;
    }
    
    
    bool check(string &word,Trie*cur,int i)
    {
        if(i==word.size())
        {
            if(cur->isEnd == true) return true;
            
            return false;
        }
        
        if(word[i]=='.')
        {
            for(int j=0;j<26;j++)
            {
                if(cur->characters[j]!= NULL)
                {
                    bool res = check(word,cur->characters[j],i+1);
                    
                    if(res==true)  return true;
            
                }
            }
        }
        
        
        else{
            int k = word[i]-'a';
            
            if(cur->characters[k]!=NULL)
            {
                bool res = check(word,cur->characters[k],i+1);
                
                return res;
            }
            
            else{
                return false;
            }
        }
        
        
        return false;
    }
    
    bool search(string word) {
        
        Trie*cur = root;
        return check(word,cur,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
