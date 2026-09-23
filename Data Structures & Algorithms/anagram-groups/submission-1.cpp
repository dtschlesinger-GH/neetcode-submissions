class Solution {
public:
    map<char, int> EncodeArray(string inString) 
    {
        map<char, int> toReturn;
        for (int index = 0; index < inString.length(); index++) 
        {
            if (toReturn.contains(inString[index])) {
                toReturn[inString[index]]++;
            }
            else {
                toReturn.emplace(inString[index], 1);
            }
        }
        return toReturn;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> toReturn;
        vector<map<char, int>> storedChars;

        if (strs.size() <= 0) {return toReturn;}

        for (int vectorIndex = 0; vectorIndex < strs.size(); vectorIndex++) 
        {
            cout << vectorIndex << endl;
            const map<char, int> charCount = EncodeArray(strs[vectorIndex]);
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
