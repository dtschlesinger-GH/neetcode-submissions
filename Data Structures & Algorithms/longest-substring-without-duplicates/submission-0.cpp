class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int leftIdx = 0;
        int rightIdx = 0;
        int maxLength = 0;
        unordered_map<char, int> currentChars;

        for (; rightIdx < s.length(); rightIdx++) 
        {
            currentChars[s[rightIdx]] += 1;
            while (currentChars[s[rightIdx]] > 1) 
            {
                currentChars[s[leftIdx]] -= 1;
                leftIdx++;
            }
            maxLength = max(maxLength, rightIdx - leftIdx + 1);
        }
    return maxLength;
    }
};
