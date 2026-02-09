class FindSumPairs {
public:
    unordered_map<int,int>nums2_record;
    int n;
    int m;
    vector<int>nums1;
    vector<int>nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int i=0;i<m;i++){
            nums2_record[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int cur_val = nums2[index];
        nums2_record[cur_val]--;
        nums2_record[cur_val + val]++;
        nums2[index] = cur_val + val;
    }
    
    int count(int tot) {
        int result = 0;
        for(auto num : nums1){
            int to_find = tot-num;
            result += nums2_record[to_find];
        }

        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
