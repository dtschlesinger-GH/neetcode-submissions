class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strIndex = 0;
        for (int i = 0; i < strs[0].length(); i++) 
        {
            for (const string& element : strs) 
            {
                if (i == element.length() || element[i] != strs[0][i]) 
                {
                    return element.substr(0, i);
                }
            }
        }
        return strs[0];
    }
};