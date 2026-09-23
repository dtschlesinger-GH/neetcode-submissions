class Solution {
public:
    vector<vector<char>> Dict = 
    {
        {},
        {},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };

    // there's a way to do this just with for loops and no stack, but I can't figure out the for loop structure
    void RecursiveBacktrack(const string& totalString, int index, vector<string>& toReturn, string& partialString) 
    {        
        if (index >= totalString.size()) 
        {
            if (totalString.size() == 0) 
            {
                return;
            }
            toReturn.push_back(partialString);
            return;
        }

        for (const char& element : Dict[totalString[index] - '0']) 
        {
            partialString += element;
            RecursiveBacktrack(totalString, index + 1, toReturn, partialString);
            partialString.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> toReturn;
        string partial = "";
        RecursiveBacktrack(digits, 0, toReturn, partial);
        return toReturn;
    }
};
