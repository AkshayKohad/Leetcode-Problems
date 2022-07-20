class Solution {
public:
    
 
    
    
    
    /**
 * Greedy
 * Since password can be letters, digits, dot or exclamation mark:
 * 1. If the password length is 3 or less, even if it's all repeating characters, only insertion is needed
 * 2. If the length is 4, like "....", 2 insertions are and 1 replacement are needed
 * 3. If the length is 5, like ".....", one insertion and might two replacements are needed
 * For the cases that length is less than 6: Math.max(requiredChar, 6 - password.length()).
 * For the case, 6<=length<=20, only replacements are needed.
 * If length is greater than 20, only replacements and deletions are needed.
 * 1. For the case of a repeated substring which length is multiple of 3 (note 3n, e.g. "aaa"), then one deletion
 *   will save a replacement to fix it
 * 2. For the case of a repeated substring which length is multiple of 3 plus 1 (note 3n+1, e.g. "aaaa"), then two
 *   deletions will save a replacement to fix it
 * 3. For the case of a repeated substring which length is multiple of 3 plus 2 (note 3n+2, e.g. "aaaaa"), then
 *   three deletions will save a replacement to fix it.
 */
  
  
 

  
 

/**
 * Get number of required characters
 * Require at least 1 lowercase letter, 1 uppercase, and 1 digit
 */
    int required_count(string password)
    {
        
        int digit = 1;
        int upper = 1;
        int lower = 1;
        
        for(auto c:password)
        {
            if(isdigit(c)) digit = 0;
            if(isupper(c)) upper = 0;
            if(islower(c)) lower = 0;
        }
        
        return digit+upper+lower;
    }
    
    int strongPasswordChecker(string password) {
        
        int size = password.length();
        int require_char = required_count(password);
        if(size<6)
        {
            return max(6-size,require_char);
        }
        
        int replace = 0; // Total replacements for repeated chars. e.g. "aaa" needs 1 replacement to fix
        int ones = 0;  // Total deletions for 3n repeated chars. e.g. "aaa" needs 1 deletion to fix  
        int twos = 0;  // Total deletions for 3n+1 repeated chars. e.g. "aaaa" needs 2 deletions to fix.
        int threes = 0;
        
        
        for(int i=0;i<password.length();)
        {
            int numsRepeated = 1;  // repeated characters
            
            while(i+numsRepeated<password.length() && password[numsRepeated+i] == password[numsRepeated+i-1])
                numsRepeated++;
            
            if(numsRepeated>=3)
            {
                replace += numsRepeated/3;
                
                int mod =  numsRepeated%3;
                
                if(mod==0) ones += 1;
                
                else if(mod==1) twos += 2;
                
                else if(mod==2) threes += 3;
                
                   
            }
            
            i = i+numsRepeated;
        }
        
         // No deletion needed when length <= 20
        
        if(size>=6 && size<=20)
            return max(require_char,replace);
        
        int deletions = size - 20;
        
         // Deleting 1 char in (3n) repeated chars can save one replacement
        replace -= min(deletions,ones);
        
        // Deleting 2 chars in (3n+1) repeated chars can save one replacement
        replace -= min(max(deletions-ones,0),twos)/2;
        
          // Deleting 3 chars in (3n+2) repeated chars can save one replacement
        replace -= max(deletions-ones-twos,0)/3;
        
        
        return deletions + max(replace,require_char);
        
        }
};
