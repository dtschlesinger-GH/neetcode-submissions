class Solution {
public:
    string minWindow(string s, string t) {
        // we are looking for character frequencies, mostly
        // we don't really care what the order or arrangement of t is, just that the num of chars it uses is in s
        // so to start, we have to make a freq map of that
        // a substring must be contiguous, so we should start at the first instance of a letter in t in s
        // we also need to make sure we used ALL the letters of t, so we will track the length
        if (t.length() > s.length()) return "";
        if (t == s) return t;

        map<char, int> tFreqMap;
        map<char, int> matchingMap;
        int remainingChars = t.length();
        string toReturn = s + "foo";

        for (const char& element : t) 
        {
            tFreqMap[element] += 1;
        }

        int leftIndex = s.find_first_of(t);
        if (t.length() == 1 && leftIndex != string::npos) 
        {
            return t;
        }
        cout << "found first letter of t at " << leftIndex << endl;
        int rightIndex = leftIndex;
        bool bHaveSubstring = false;

        // so now that we found the first shared character, what is our sliding window logic?
        // move the window forward until you find all characters, keep a freq map of what you have
        // once you successfully match all characters, you know where the right index is is the last needed char, and can't be replaced
        // start sliding your left window forward
        // see if you can decrement what your left index is looking at and still match
        // if you can, do so.  If you can't, record the current substring, and then move your left foward one
        // then go back to sliding your right.
        // each time you get all the required chars, it will end with a record check, and then moving left until you are invalid
        // therefore, when right hits the end, if it didn't trigger a check, there's no way to get a full string there
        // after all, literally every time you hit all needed chars, we will trigger

        for (; rightIndex < s.length(); rightIndex++) 
        {
            char currentChar = s[rightIndex];
            matchingMap[currentChar] += 1;
            if (matchingMap[currentChar] <= tFreqMap[currentChar]) 
            {
                remainingChars--;
            }
            cout << "right index: " << rightIndex << ", leftIndex: " << leftIndex << " looking at char " << currentChar << " with freqeuncy " << matchingMap[currentChar] << ", " << tFreqMap[currentChar] << " remaining chars " << remainingChars << endl;
            while (remainingChars == 0) 
            {
                cout << "attempting to record new substring" << endl;
                char leftChar = s[leftIndex];
                int strLen = rightIndex - leftIndex + 1;
                if (strLen < toReturn.length()) 
                {
                    toReturn = s.substr(leftIndex, strLen);
                    cout << "recorded new substring " << toReturn;
                    bHaveSubstring = true;
                }

                matchingMap[leftChar] -= 1;
                if (matchingMap[leftChar] < tFreqMap[leftChar]) 
                {
                    remainingChars++;
                }
                leftIndex++;
            }
        }
        return !bHaveSubstring ? "" : toReturn;
    }
};
