class Trie{

    public:
    bool isEnd;
    Trie* character[26];
    
    Trie()
    {
        isEnd = false;
        
        for(int i=0;i<26;i++)
        {
            character[i] = NULL;
        }
    }
    
};


void insert(Trie*root,string s)
{
    Trie*p = root;
    
    for(int i=0;i<s.length();i++)
    {
       int k = s[i]-'a';
        
        if(p->character[k]==NULL)
        {
            p->character[k] = new Trie();
            
            
        }
        
        p = p->character[k];
        
        
    }
    
    p->isEnd = true;
}

void search(Trie*head,string &d,vector<string>&ans)
{
    if(ans.size()==3)
        return;
    
    if(head->isEnd == true)
    {
        ans.push_back(d);
        
    }
    
    for(int i=0;i<26;i++)
    {
        if(head->character[i]==NULL)
            continue;
        
        char ch = 'a' + i;
        
        d.push_back(ch);
        
        search(head->character[i],d,ans);
        
        d.pop_back();
    }
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        
        Trie*root = new Trie();
        
        for(int i=0;i<products.size();i++)
        {
            insert(root,products[i]);
        }
        
        string w;
        vector<vector<string>>res;
        Trie*t = root;
         for(int i=0;i<searchWord.length();i++)
        {
            w.push_back(searchWord[i]);
            
            int k = searchWord[i]-'a';
            t = t->character[k];
            
            if(t==NULL)
                break;
            
            string d = w;
            vector<string>ans;
            
            
            
           search(t,d,ans);
            
            res.push_back(ans);
        }
        
        int diff = searchWord.length()-res.size();
        
        while(diff--)
        {
           res.push_back({});
        }
        return res;
    }
};
