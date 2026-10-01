class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (internalStack.empty()) {
            internalStack.push_back(0);
            internalMin = val;
        }
        else {
            internalStack.push_back(val - internalMin);
            if (val < internalMin) {
                internalMin = val;
            }
        }
    }
    
    void pop() {
        if (!internalStack.empty()) {
            long pop = internalStack[internalStack.size() - 1];
            internalStack.pop_back();
            if (pop < 0) {
                internalMin -= pop;
            }
        }
    }
    
    int top() {
        long minDiff = internalStack[internalStack.size() - 1];
        return (minDiff > 0) ? (minDiff + internalMin) : (int)internalMin;
    }
    
    int getMin() {
        return (int)internalMin;
    }

    long internalMin;
    vector<long> internalStack;

};
