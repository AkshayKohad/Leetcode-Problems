class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<chars.length();i++)
        {
            mp[chars[i]] = vals[i];
        }
        
        vector<int>arr;
        
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
            arr.push_back(mp[s[i]]);
            }
            
            else{
                int ch = s[i]-'a'+1;
                
                arr.push_back(ch);
            }
        }
        
        int max_res = 0;
        int sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            sum = sum + arr[i];
            
            if(sum<0)
                sum=0;
            
            max_res = max(max_res,sum);
        }
        
        return max_res;
    }
};
