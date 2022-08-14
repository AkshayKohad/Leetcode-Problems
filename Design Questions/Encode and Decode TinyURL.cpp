class Solution {
public:

    map<string,int>mp;
    
    int counter = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mp[longUrl] = counter++;
        
        return to_string(mp[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        int val = stoi(shortUrl);
        
        for(auto k:mp)
        {
            if(k.second == val)
                return k.first;
            
        }
        
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
