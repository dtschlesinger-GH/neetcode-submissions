class Solution {
public:
    enum Operation 
    {
        Add,
        Sub,
        Mult,
        Div,
        NONE
    };

    Operation ConvertOperation(const string& op) 
    {
        if (op == "+") 
        {
            return Add;
        }
        else if (op == "-") 
        {
            return Sub;
        }
        else if (op == "*") 
        {
            return Mult;
        }
        else if (op == "/") 
        {
            return Div;
        }
        else 
        {
            return NONE;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        for (const string& element : tokens) 
        {
            {
                const Operation& toPerform = ConvertOperation(element);
                switch(toPerform) 
                {
                    case Add:
                    {
                        int rhs = values.top();
                        values.pop();
                        int lhs = values.top();
                        values.pop();
                        values.push(lhs + rhs);
                        break;
                    }    
                    case Sub:
                    {
                        int rhs = values.top();
                        values.pop();
                        int lhs = values.top();
                        values.pop();
                        values.push(lhs - rhs);
                        break;
                    }
                    case Mult: 
                    {
                        int rhs = values.top();
                        values.pop();
                        int lhs = values.top();
                        values.pop();
                        values.push(lhs * rhs);
                        break;
                    }
                    case Div: 
                    {
                        int rhs = values.top();
                        values.pop();
                        int lhs = values.top();
                        values.pop();
                        values.push(lhs / rhs);
                        break;
                    }
                    case NONE: 
                    {
                        values.push(stoi(element));
                    }
                }
            }
        }
        return values.top();
    }
};
