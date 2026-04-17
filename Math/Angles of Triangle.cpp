class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());

        if(sides[0]+sides[1]<=sides[2])return {};

        const double PI = 3.141592653589793;
        vector<double>result;

        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        
        double angleA_rad = acos((b*b + c*c - a*a) / (2 * b * c));
        double angleA_deg = angleA_rad * (180.0/PI);

        double angleB_rad = acos((a*a + c*c - b*b) / (2 * a * c));
        double angleB_deg = angleB_rad * (180.0/PI);

        double angleC_rad = acos((b*b + a*a - c*c) / (2 * b * a));
        double angleC_deg = angleC_rad * (180.0/PI);

        result = {angleA_deg,angleB_deg,angleC_deg};
        sort(result.begin(),result.end());
        return result;
    }
};
