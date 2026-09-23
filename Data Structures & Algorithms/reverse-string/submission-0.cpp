class Solution {
public:
    void reverseString(vector<char>& s) {
        int leftIndex = 0;
        int rightIndex = s.size() - 1;

        while (leftIndex < rightIndex) 
        {
            char temp = s[leftIndex];
            s[leftIndex] = s[rightIndex];
            s[rightIndex] = temp;
            leftIndex++;
            rightIndex--;
        }
    }
};