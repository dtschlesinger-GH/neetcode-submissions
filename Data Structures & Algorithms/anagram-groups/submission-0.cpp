class Solution {
public:
    vector<int> EncodeArray(string inString) 
    {
        vector<int> toReturn(26,0);
        for (int index = 0; index < inString.length(); index++) 
        {
            //int test = inString[index] - 'a';
            //cout << test << endl;
            toReturn[inString[index] - 'a']++;
        }
        return toReturn;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> toReturn;
        vector<vector<int>> storedChars;

        if (strs.size() <= 0) {return toReturn;}

        for (int vectorIndex = 0; vectorIndex < strs.size(); vectorIndex++) 
        {
            cout << vectorIndex << endl;
            const vector<int> charCount = EncodeArray(strs[vectorIndex]);
            auto itr = std::find(storedChars.begin(), storedChars.end(), charCount);
            if (itr != storedChars.end()) 
            {
                toReturn[itr - storedChars.begin()].push_back(strs[vectorIndex]);
            }
            else 
            {
                storedChars.push_back(charCount);
                toReturn.push_back({strs[vectorIndex]});
            }
        }

        return toReturn;
    }
};
