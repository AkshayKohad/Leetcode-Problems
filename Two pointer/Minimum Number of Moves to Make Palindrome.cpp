//Approach 1
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int moves = 0;
    
    for (int i = 0, j = s.size() - 1; i < j; ++i) {
        int k = j;
        for (; k > i; --k){
            if (s[i] == s[k]) {
                for (; k < j; ++k) {
                    std::swap(s[k], s[k + 1]);
                    ++moves;
                }
                --j;
                break;
            }
        }
        if (k == i)
            moves += s.size() / 2 - i;
      }
      cout<<s<<endl;
      return moves;
    }
};
//"xjjww" - Use this example to understand, why we cannot swap middle element, because it will change the position again
// if we change the position
// xjjww -> jjxww -> x position should not change as we have already added cost to fix it's position
// now, jjxww -> jxwwj -> see position of x got compromised then we need addtional cost for x. That is why we are not changing. So we will first fix all elements except middle and then shift 
// x to middle at last. This is optimal -> 2nd last xjwwj -> jwxwj
