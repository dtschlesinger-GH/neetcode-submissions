class Solution {
public:

    string encode(vector<string>& strs) {
        string toReturn = "";
        for (const string& element : strs) {
            toReturn += (element + '\n');
        }
        return toReturn;
    }

    vector<string> decode(string s) {
        vector<string> toReturn;
        string parsedString = "";
        char delimiter = '\n';
        for (int index = 0; index < s.length(); index++) 
        {
            if (s[index] == '\n') 
            {
                toReturn.push_back(parsedString);
                parsedString = "";
                continue;
            }
            parsedString += s[index];
        }
        return toReturn;
    }
};
