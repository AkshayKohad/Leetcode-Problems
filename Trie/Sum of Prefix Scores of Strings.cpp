class Solution {
public:
    
    class Trie{
      
        public:
        
        int freq;
        Trie* characters[26];
        
        Trie()
        {
            freq = 1;
            
            for(int i=0;i<26;i++)
            {
                characters[i] = NULL;
            }
        }
        
    };
    
    void insert(Trie*root,string s)
    {
        Trie*p = root;
        
        for(int i=0;i<s.length();i++)
        {
            //p->freq++;
            int k = s[i]-'a';
            
            
            if(p->characters[k]==NULL)
            {
                p->characters[k] = new Trie();
                
            }
            
            else{
                p->characters[k]->freq++;
            }
                        
            p=p->characters[k];
        }
    }
    
   
    void search(Trie*root,string s,int &count)
    {
        Trie*p = root;
        
        for(int i=0;i<s.length();i++)
        {
            int k = s[i]-'a';
            
            count += p->characters[k]->freq;
            
            p = p->characters[k];
        }
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        Trie*root = new Trie();
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            insert(root,words[i]);
        }
        
        
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            int count = 0;
            search(root,words[i],count);
            
            res.push_back(count);
        }
        
        return res;
    }
};
