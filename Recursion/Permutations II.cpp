class Solution {
public:
    vector<vector<int>> ans;

void get_per(vector<int>& A,int idx){
    if(idx==A.size()-1) ans.push_back(A);
    map<int,bool> mp;
    for(int i=idx;i<A.size();i++){
        
        if(mp[A[i]]) continue;
        else {
            mp[A[i]] = true;
            swap(A[i],A[idx]);
            get_per(A,idx+1);
            swap(A[i],A[idx]);
        }
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    
    get_per(nums,0);
    return ans;
}
};
