class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> openPunc;
        for (const char& element : s) 
        {
            switch(element) 
            {
                case '(': 
                {
                    cout << "found open paren" << endl;
                    openPunc.push(element);
                    break;
                }
                case '[': 
                {
                    cout << "found open bracket" << endl;
                    openPunc.push(element);
                    break;
                }
                case '{': 
                {
                    cout << "found open brace" << endl;
                    openPunc.push(element);
                    break;
                }
                case ')': 
                {
                    cout << "found closed paren" << endl;
                    if (openPunc.size() > 0) 
                    {
                        if (openPunc.top() == '(') 
                        {
                            openPunc.pop();
                        }
                        else 
                        {
                            return false;
                        }
                    }
                    else 
                    {
                        return false;
                    }
                    break;
                }
                case '}': 
                {
                    cout << "found closed brace" << endl;
                    if (openPunc.size() > 0) 
                    {
                        if (openPunc.top() == '{') 
                        {
                            openPunc.pop();
                        }
                        else 
                        {
                            return false;
                        }
                    }
                    else 
                    {
                        return false;
                    }
                    break;
                }
                case ']': 
                {
                    cout << "found closed bracket" << endl;
                    if (openPunc.size() > 0) 
                    {
                        if (openPunc.top() == '[') 
                        {
                            openPunc.pop();
                        }
                        else 
                        {
                            return false;
                        }
                    }
                    else 
                    {
                        return false;
                    }
                    break;
                }
                default:
                    return false;
            }
        }
        return openPunc.size() == 0;
    }
};
