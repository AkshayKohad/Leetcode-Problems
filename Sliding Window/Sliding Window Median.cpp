class Solution {
public:
    void balance(multiset<int>&min_val, multiset<int>&max_val){
        if(min_val.size()==max_val.size() || max_val.size()==min_val.size()+1)return;

        if(max_val.size()<min_val.size()){
            auto it = min_val.begin();
            max_val.insert(*it);
            min_val.erase(it);
        }else if(max_val.size()>min_val.size()+1){
            auto it = prev(max_val.end());
             min_val.insert(*it);
            max_val.erase(it);
        }
    }
    void add_element(multiset<int>&min_val,multiset<int>&max_val,int num){
            
            if(max_val.size() == min_val.size()){
                if(max_val.size()==0){
                    max_val.insert(num);
                }else{
                    auto it = min_val.begin();
                    int val = *it;

                    if(val < num){
                        min_val.erase(it);
                        min_val.insert(num);
                        max_val.insert(val);
                    }else{
                        max_val.insert(num);
                    }
                }
            }else{
                auto it = prev(max_val.end());
                int val = *it;

                if(val > num){
                    max_val.erase(it);
                    max_val.insert(num);
                    min_val.insert(val);

                }else{
                    min_val.insert(num);
                }
                
            }
    }

    double find_median(int k,multiset<int>&min_val,multiset<int>&max_val){
        if(k%2){
                int val = *max_val.rbegin();
                return (double)val;
                
        }else{
            int val = *max_val.rbegin();
            int val1 = *min_val.begin();

            double ans = ((double)val + (double)val1)/2.0;   
            return ans;
        }
        return 0.0;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int>max_val;
        multiset<int>min_val;

        for(int i=0;i<k;i++){    
            add_element(min_val,max_val,nums[i]);
        }
        vector<double>result;
        double ans = find_median(k,min_val,max_val);
        result.push_back(ans);

        //return result;
        int j=k;
        int i=0;

        while(j<n){
            
            if(max_val.find(nums[i])!=max_val.end()){
                auto it = max_val.find(nums[i]);
                max_val.erase(it);
            }else{
                auto it = min_val.find(nums[i]);
                min_val.erase(it);
            }

            balance(min_val,max_val);
            add_element(min_val,max_val,nums[j]);
            i++;
            j++;
            double ans = find_median(k,min_val,max_val);
            result.push_back(ans);

        }

        return result;
    }
};
