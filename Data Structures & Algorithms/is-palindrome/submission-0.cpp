class Solution {
public:
    bool isPalindrome(string s) {
        int leftPos = 0;
        int rightPos = s.length() - 1;
        bool toReturn = true;
        while (!isalnum(s[leftPos])) {leftPos++;}
        while (!isalnum(s[rightPos])) {rightPos--;}


        while(leftPos < rightPos && toReturn == true) 
        {
            cout << "comparing " << tolower(s[leftPos]) << " and " << tolower(s[rightPos]);
            if (tolower(s[leftPos]) != tolower(s[rightPos])) 
            {
                toReturn = false;
            }
            leftPos++;
            while (!isalnum(s[leftPos])) {leftPos++;}
            rightPos--;
            while (!isalnum(s[rightPos])) {rightPos--;}
        }
        return toReturn;
    }
};
