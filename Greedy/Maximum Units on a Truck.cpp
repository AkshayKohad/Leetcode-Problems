class Solution {
public:
    static bool mycmp(vector<int>&first,vector<int>&second){
        return first[1] > second[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),mycmp);
        int n = boxTypes.size();
        int result = 0;
        int i=0;
        while(i<n && truckSize>0){
            int units = boxTypes[i][1];
            int boxCount = boxTypes[i][0];

            int cnt = min(truckSize,boxCount);
            result += cnt*units;
            truckSize -= cnt;
            i++;
        }
        return result;
    }
};
