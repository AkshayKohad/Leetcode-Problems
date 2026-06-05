class Trie{
    private:
    
    bool isEnd;
    int cnt_pattern;
    Trie*character[26];
    public:
    
    Trie(){
        isEnd = false;
        cnt_pattern = 0;
        for(int i=0;i<26;i++)character[i] = NULL;
    }
    
    void insert(string s){
        Trie*cur = this;
        
        for(int i=0;i<s.length();i++){
            int ch = s[i]-'a';
            if(cur->character[ch] == NULL){
                cur->character[ch] = new Trie();
            }
            cur = cur->character[ch]; 
        }
        
        cur->isEnd = true;
        cur->cnt_pattern++;
    }
    
    void traverse(vector<pair<int,string>>&result,int &k,string &s){
        Trie*cur = this;
        
        if(cur->isEnd){
            result.push_back({cur->cnt_pattern,s});
        }
        for(int i=0;i<26;i++){
            if(cur->character[i] == NULL)continue;
            s.push_back(i+'a');
            cur->character[i]->traverse(result,k,s);
            s.pop_back();
        }
        
    }
    
};

bool mycmp(pair<int,string>f,pair<int,string>s){
    if(f.first == s.first){
        return f.second < s.second;
    }
    return f.first > s.first;
}
vector<string> TopKFrequentWords(const vector<string>& words, int k) 
{
    // Replace this placeholder return statement with your code
    Trie*root = new Trie();
    for(auto word : words){
        root->insert(word);
    }
    string traverse;
    vector<pair<int,string>>result;
    root->traverse(result,k,traverse);
    
    sort(result.begin(),result.end(),mycmp);
    int sz = result.size();
    vector<string>ans;
    for(int i=0;i<min(k,sz);i++){
        ans.push_back(result[i].second);
    }
    return ans;
}
