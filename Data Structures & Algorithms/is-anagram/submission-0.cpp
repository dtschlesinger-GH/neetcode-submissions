#include <set>
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::multiset<char> foundChars;
        for (int index = 0; index < s.length(); index++) 
        {
            foundChars.emplace(s[index]);
        }

        for (int index = 0; index < t.length(); index++) 
        {
            auto itr = foundChars.find(t[index]);
            if (itr != foundChars.end()) 
            {
                foundChars.erase(itr);
            }
            else 
            {
                return false;
            }
        }

        if (foundChars.empty()) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};
