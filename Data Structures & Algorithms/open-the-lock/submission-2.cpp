class Solution {
public:
    unordered_set<string> visited;
    int minMoves = -1;

    void RecursiveBacktrack(string position, int totalMoves) 
    {
        if (position == "0000") 
        {
            cout << "Found solution in " << totalMoves << " moves" << endl;
            if (minMoves < 0) 
            {
                minMoves = totalMoves;
            }
            else 
            {
                minMoves = min(totalMoves, minMoves);
            }
            return;
        }

        if (visited.contains(position)) 
        {
            return;
        }

        visited.insert(position);

        
    }

    int openLock(vector<string>& deadends, string target) 
    {
        for (const string& element : deadends) 
        {
            if (element == "0000") 
            {
                return  -1;
            }
            visited.insert(element);
        }
        
        int totalMoves = 0;
        queue<string> bfsQueue;
        bfsQueue.push(target);

        while (!bfsQueue.empty()) 
        {
            int iterationSize = bfsQueue.size();
            for (int i = 0; i < iterationSize; i++) 
            {
                string currentPos = bfsQueue.front();
                bfsQueue.pop();
                if (currentPos == "0000") 
                {
                    cout << "Found target at total moves " << totalMoves << endl;
                    return totalMoves;
                }
                if (visited.contains(currentPos)) 
                {
                    continue;
                }
                visited.insert(currentPos);

                for (int i = 0; i < currentPos.length(); i++) 
                {
                    char holder = currentPos[i];
                    currentPos[i] += 1;
                    if (currentPos[i] - '0' >= 10) 
                    {
                        currentPos[i] = '0';
                    }
                    bfsQueue.push(currentPos);
                    currentPos[i] = holder;

                    currentPos[i] -= 1;
                    if (currentPos[i] - '0' < 0) 
                    {
                        currentPos[i] = '9';
                    }
                    bfsQueue.push(currentPos);
                    currentPos[i] = holder;
                }
            }
            totalMoves += 1;
        }
        return -1;    
    }
};