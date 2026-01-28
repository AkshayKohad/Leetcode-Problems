class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int start_ind = 0;
        int n = nums.size();
        while(start_ind<n){
            int slow = start_ind;
            int fast = start_ind;

            do{
                //Slow Pointer
                slow = (slow + (nums[slow] > 0 ? nums[slow] : -(abs(nums[slow]))%n+n))%n;

                //Fast Pointer
                fast = (fast + (nums[fast] > 0 ? nums[fast] : -(abs(nums[fast]))%n+n))%n;
                fast = (fast + (nums[fast] > 0 ? nums[fast] : -(abs(nums[fast]))%n+n))%n;
                
            }while(slow!=fast);

            int next_ind = (slow + (nums[slow] > 0 ? nums[slow] : -(abs(nums[slow]))%n+n))%n;
            
            if(next_ind == slow){
                start_ind++;
                continue;
            }

            int cur_ind = slow;
            bool direction_forward = nums[slow] > 0 ? true:false;
            bool isCycle = true;
            do{
                if(nums[cur_ind]>0 && direction_forward == false){
                    isCycle = false;
                    break;
                }else if(nums[cur_ind]<0 && direction_forward == true){
                    isCycle = false;
                    break;
                }

                cur_ind = (cur_ind + (nums[cur_ind] > 0 ? nums[cur_ind] : -(abs(nums[cur_ind]))%n+n))%n;
            }while(cur_ind != slow); 

            if(isCycle == false)
            start_ind++;
            else return true;
        }

        return false;
    }
};
