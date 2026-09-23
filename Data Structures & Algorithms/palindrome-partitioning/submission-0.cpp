class Solution {
public:

    bool PalendromeCheck(string toCheck, int leftIndex, int rightIndex) 
    {
        while (leftIndex < rightIndex) 
        {
            if (toCheck[leftIndex] != toCheck[rightIndex]) 
            {
                return false;
            }
            leftIndex++;
            rightIndex--;
        }
        return true;
    }

    void RecursiveBacktrack(int stringStartIndex, const string& totalString, vector<string>& partialStrings, vector<vector<string>>& toReturn)  
    {
        if (stringStartIndex >= totalString.length()) 
        {
            toReturn.push_back(partialStrings);
            return;
        }

        for (int rightIndex = stringStartIndex; rightIndex < totalString.length(); rightIndex++) 
        {
            if (PalendromeCheck(totalString, stringStartIndex, rightIndex)) 
            {
                partialStrings.push_back(totalString.substr(stringStartIndex, rightIndex - stringStartIndex + 1));
                RecursiveBacktrack(rightIndex + 1, totalString, partialStrings, toReturn);
                partialStrings.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> toReturn;
        vector<string> partialString;

        RecursiveBacktrack(0, s, partialString, toReturn);
        return toReturn;
    }
};
