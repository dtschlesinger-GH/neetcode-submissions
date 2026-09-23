class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto comparator = [](const pair<int, char>& lhs, const pair<int, char>& rhs) {return lhs.first < rhs.first;};
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comparator)> pHeap;
        string toReturn = "";
        int repeatCount = 0;

        if (a > 0)
            pHeap.push({a, 'a'});
        if (b > 0)
            pHeap.push({b, 'b'});
        if (c > 0)
            pHeap.push({c, 'c'});
        char prevChar = '#';

        while (!pHeap.empty()) 
        {
            if (!toReturn.empty()) 
            {
                prevChar = toReturn[toReturn.length() - 1];
            }
            pair<int, char> top = pHeap.top();
            pHeap.pop();

            // this is calculated pre-insert, as a prediction
            if (top.second == prevChar) 
            {
                repeatCount++;
            }
            else 
            {
                repeatCount = 1;
            }           

            if (repeatCount < 3) 
            {
                toReturn += (top.second);
                top.first--;
                if (top.first > 0) 
                {
                    pHeap.push(top);
                }
            }
            else 
            {
                if (pHeap.empty()) 
                {
                    return toReturn;
                }
                pair<int, char> secondTop = pHeap.top();
                pHeap.pop();
                toReturn += (secondTop.second);
                secondTop.first -= 1;
                if (secondTop.first > 0) 
                {
                    pHeap.push(secondTop);
                }
                pHeap.push(top);
            }
        }

        return toReturn;
    }
};