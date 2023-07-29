class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        
        int m = forbidden.size();
        
        unordered_set<string>st;
        for(int i=0;i<m;i++)
        {
            st.insert(forbidden[i]);
        }
        
        int n = word.length();
        
        vector<int>start_idx(n,-1);
        for(int i=0;i<n;i++)
        {
            string temp;
            for(int j=i;j<n && j<i+10;j++)
            {
                temp.push_back(word[j]);
                
                if(st.find(temp)!=st.end())
                {
                    start_idx[j] = max(start_idx[j],i);
                }
            }
        }
        
        int start = 0;
        int i=0;
        
        int count = 0;
        int result = 0;
        
        while(i<n)
        {
            if(start_idx[i]==-1)
            {
                i++;
                count++;
            }
            
            else{
                start = max(start,start_idx[i]+1);
                count = i-start+1;
                i++;
                
            }
            
            result = max(result,count);
        }
        
        return result;
    }
};
