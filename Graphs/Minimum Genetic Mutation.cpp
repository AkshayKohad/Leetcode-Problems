class Solution {
public:
    
    vector<char>genes = {{'A'},{'C'},{'G'},{'T'}};
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
     
        set<string>record;
        
        set<string>visited;
        
        for(int i=0;i<bank.size();i++)
        {
            record.insert(bank[i]);
        }
        
        queue<pair<string,int>>q;
        
        visited.insert(startGene);
        
        q.push({startGene,0});
        
        
        while(q.empty()==false)
        {
            pair<string,int>cur = q.front();
            q.pop();
            
            string s = cur.first;
            
            int moves = cur.second;
            
            if(s==endGene)
                return moves;
            
            for(int i=0;i<s.length();i++)
            {
                for(auto ch : genes)
                {
                    string upd = s;
                    
                    if(upd[i]==ch)
                        continue;
                    
                    upd[i] = ch;
                    
                    if(record.find(upd)==record.end())
                        continue;
                    
                    if(visited.find(upd)!=visited.end())
                        continue;
                    
                    visited.insert(upd);
                    q.push({upd,moves+1});
                }
            }
        }
        
        return -1;
    }
};
