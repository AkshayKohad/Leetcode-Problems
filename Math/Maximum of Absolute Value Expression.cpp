class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        

        int n = arr1.size();
        
        //int max_res1 = max_res2 = max_res3 = max_res4 =INT_MIN;

        int final_result = INT_MIN;

        //case 1 (a1[i]+a2[i]+i) - (a1[j]+a2[j]+j)
        //case 2 (a1[i]-a2[i]+i) - (a1[j]-a2[j]+j)
        //case 3 (a2[i]-a1[i]+i) - (a2[j]-a1[j]+j)
        //case 4 (i-a1[i]-a2[i]) - (i-a1[i]-a2[i])

 // In all cases     MAXIMUM     -     MINIMUM
     
        int case1_max = INT_MIN;
        int case1_min = INT_MAX;
        int case2_max = INT_MIN;
        int case2_min = INT_MAX;
        int case3_max = INT_MIN;
        int case3_min = INT_MAX;
        int case4_max = INT_MIN;
        int case4_min = INT_MAX;

        for(int i=0;i<n;i++)
        {
            case1_max = max(case1_max,arr1[i]+arr2[i]+i);
            case1_min = min(case1_min,arr1[i]+arr2[i]+i);

            case2_max = max(case2_max,arr1[i]-arr2[i]+i);
            case2_min = min(case2_min,arr1[i]-arr2[i]+i);

            case3_max = max(case3_max,arr2[i]-arr1[i]+i);
            case3_min = min(case3_min,arr2[i]-arr1[i]+i);

            case4_max = max(case4_max,i-arr1[i]-arr2[i]);
            case4_min = min(case4_min,i-arr1[i]-arr2[i]);
        }

        final_result = max({final_result,case1_max-case1_min,case2_max-case2_min,case3_max-case3_min,case4_max-case4_min});

        return final_result;

    }
};
