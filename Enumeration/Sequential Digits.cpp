class Solution {
public:
    int find_low(vector<int>&all_sequential,int low){
        int l = 0;
        int r = all_sequential.size()-1;

        while(l<=r){
            int mid = (l+r)/2;
            if(all_sequential[mid] == low)return mid;

            if(all_sequential[mid]<low){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
    int find_high(vector<int>&all_sequential,int high){
        int l = 0;
        int r = all_sequential.size()-1;

        while(l<=r){
            int mid = (l+r)/2;
            if(all_sequential[mid] == high)return mid;

            if(all_sequential[mid]>high){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>all_sequential;
        for(int i=1;i<=9;i++){
            int val = 0;
            for(int j=i;j<=9;j++){
                val = val*10 + j;
                all_sequential.push_back(val);
            }
        }
        sort(all_sequential.begin(),all_sequential.end());

        int index_start = find_low(all_sequential,low);
        int index_end = find_high(all_sequential,high);

        if(index_start == all_sequential.size() || index_end == -1)return {};

        vector<int>result;
        for(int i=index_start;i<=index_end;i++){
            result.push_back(all_sequential[i]);
        }

        return result;
    }
};
