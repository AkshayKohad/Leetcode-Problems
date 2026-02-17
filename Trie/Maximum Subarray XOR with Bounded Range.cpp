class TrieNode{
public:
    TrieNode* child[2];
    int count;
    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
        count = 0;
    }
};

class Trie{
public:
    TrieNode* root = new TrieNode();

    void insert(int val){
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){          // FIX: use 32 bits
            int ch = (val >> i) & 1;
            if(node->child[ch] == NULL)
                node->child[ch] = new TrieNode();
            node = node->child[ch];
            node->count++;
        }
    }

    void remove(int num){
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){          // FIX: use 32 bits
            int ch = (num >> i) & 1;
            node = node->child[ch];
            node->count--;
        }
    }

    int maxXor(int num){
        TrieNode* node = root;
        int result = 0;
        for(int i = 31; i >= 0; i--){          // FIX: use 32 bits
            int ch = (num >> i) & 1;
            if(node->child[1 - ch] != NULL && node->child[1 - ch]->count > 0){
                result |= (1 << i);            // FIX: bit operation instead of pow
                node = node->child[1 - ch];
            } else {
                node = node->child[ch];
            }
        }
        return result;
    }
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        Trie* head = new Trie();
        int n = nums.size();
        deque<int> max_dq;
        deque<int> min_dq; 
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] ^ nums[i];
        int result = 0;
        int l = 0, r = 0;
        head->insert(0);
        while(r < n){
            while(!max_dq.empty() && nums[max_dq.back()] <= nums[r])
                max_dq.pop_back();
            while(!min_dq.empty() && nums[min_dq.back()] >= nums[r])
                min_dq.pop_back();
            max_dq.push_back(r);
            min_dq.push_back(r);
            while(nums[max_dq.front()] - nums[min_dq.front()] > k){
                if(l == max_dq.front()) max_dq.pop_front();
                if(l == min_dq.front()) min_dq.pop_front();
                head->remove(prefix[l]);       
                l++;
            }
            result = max(result, head->maxXor(prefix[r + 1]));
            head->insert(prefix[r + 1]);
            r++;                               
            while(max_dq.size()>0 && max_dq.front()<l) max_dq.pop_front();
            while(min_dq.size()>0 && min_dq.front()<l) min_dq.pop_front();
        }

        return result;
    }
};
