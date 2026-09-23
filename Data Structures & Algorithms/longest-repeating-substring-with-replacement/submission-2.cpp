class Solution {
public:
    int characterReplacement(string s, int k) {
        int charFreq = 0;
        int leftIdx = 0;
        int rightIdx = 0;
        int toReturn = 0;
        int maxFreq = 0;
        map<char, int> charFreqMap;

        for (; rightIdx < s.length(); rightIdx++) 
        {
            charFreqMap[s[rightIdx]] += 1;
            maxFreq = max(charFreqMap[s[rightIdx]], maxFreq);

            while ((rightIdx - leftIdx + 1) - maxFreq > k) {
                charFreqMap[s[leftIdx]] -= 1;
                leftIdx++;
            }
            toReturn = max(toReturn, rightIdx - leftIdx + 1);
        }
        return toReturn;
    }
};
