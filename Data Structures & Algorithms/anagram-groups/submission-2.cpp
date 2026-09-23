class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramKeys;
        for (int vectorIndex = 0; vectorIndex < strs.size(); vectorIndex++) 
        {
            vector<int> numCounts(26,0);
            for (int stringIndex = 0; stringIndex < strs[vectorIndex].size(); stringIndex++) 
            {
                numCounts[strs[vectorIndex][stringIndex] - 'a']++;
            }
            string key;
            for (int countIndex = 0; countIndex < 26; countIndex++) 
            {
                key += numCounts[countIndex];
            }
            anagramKeys[key].push_back(strs[vectorIndex]);
        }

        vector<vector<string>> toReturn;
        for (const auto& keyValPairs : anagramKeys) {
            toReturn.push_back(keyValPairs.second);
        }
        return toReturn;
    }
};
