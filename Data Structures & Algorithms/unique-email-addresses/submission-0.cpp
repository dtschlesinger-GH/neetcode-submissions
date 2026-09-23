class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> validEmails;
        
        for (const string element : emails) 
        {
            string localName = "";
            string domainName = "";
            const int separatorLoc = element.find('@');
            localName = element.substr(0, separatorLoc);
            domainName = element.substr(separatorLoc);
            string convertedLocalName = "";
            for (const char letter : localName) 
            {
                if (letter == '.') 
                {
                    continue;
                }
                if (letter == '+') 
                {
                    break;
                }
                convertedLocalName.push_back(letter);
            }
            validEmails.insert((convertedLocalName + domainName));
            // domain name, any and all alterations create a new domain.
            // local name, we just scan through removing all . until we hit a +, this can actually just be a write to a new string
            // if we hit a +, we run this
        }
        return validEmails.size();
    }
};