class Solution {
public:
    bool checkValidString(string s) {
        // stack for left paren and right paren
        // for any remaining left over, you can use the stars
        stack<int> leftParenStack;
        int unmatchedCounter = 0;
        stack<int> starStack;

        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == '(') 
            {
                leftParenStack.push(i);
            }
            if (s[i] == ')') 
            {
                if (!leftParenStack.empty()) 
                {
                    leftParenStack.pop();
                }
                else if (!starStack.empty()) 
                {
                    starStack.pop();
                }
                else 
                {
                    // if you get an open paren when you don't have a left paren or a wildcard to match it, its just over
                    // we can't do swaps or replacements, so nothing from then on will make the string valid
                    return false;
                }
            }
            if (s[i] == '*') 
            {
                starStack.push(i);
            }
        }
        while (!leftParenStack.empty()) 
        {
            int leftParenIndex = leftParenStack.top();
            if (starStack.empty()) 
            {
                return false;
            }
            int starIndex = starStack.top();
            if (leftParenIndex < starIndex) 
            {
                // if we pop the last left paren off here, we exit.
                // if we pop the last star index while there's still left parens, we are doomed, we return false
                leftParenStack.pop();
                starStack.pop();
            }    
            else 
            {
                // we have a left paren coming after the latest star and it wasn't matched when going through the string
                // this means we are doomed to be invalid, so return false
                return false;
            }
        }
        // if we got through all this nonsense, we can return true
        return true;
    }
};
