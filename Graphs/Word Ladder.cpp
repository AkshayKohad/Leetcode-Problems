class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string>s;
        int flag=0;
        for(int i=0;i<wordList.size();i++)
        {
            if(wordList[i]==endWord)
                flag=1;
            
            s.insert(wordList[i]);
        }
        
        if(flag==0)
            return 0;
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        
        while(q.empty()==false)
        {
            pair<string,int>curr = q.front();
            q.pop();
            
            string a = curr.first;
            int moves = curr.second;
            
            for(int i=0;i<a.length();i++)
            {
                char ch = a[i];
                for(char c = 'a'; c<='z';c++)
                {
                    if(ch==c)
                        continue;
                    
                    a[i] = c;
                    
                    if(s.find(a)!=s.end())
                    {
                        if(a == endWord)
                            return moves+1;
                        
                        q.push({a,moves+1});
                        s.erase(a);
                        
                    }
                    
                    a[i] = ch;
                }
            }
        }
        
        return 0;
    }
};
