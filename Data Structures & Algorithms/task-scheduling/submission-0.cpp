class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int timestep = 0;
        vector<int> freqMap(26,0);
        for (const char& element : tasks) 
        {
            freqMap[element - 'A'] += 1;
        }

        priority_queue<int> maxHeap;

        for (const int& element : freqMap) 
        {
            if (element > 0) 
            {
                maxHeap.push(element);
            }
        }

        cout << "Heap size: " << maxHeap.size() << endl;
        int currentCycle = 0;
        queue<pair<int, int>> cooldownQueue;
        while (!maxHeap.empty() || !cooldownQueue.empty())  
        {
            if (maxHeap.size() > 0) 
            {
                int cooldownTimestamp = currentCycle + n;
                if (maxHeap.top() - 1 > 0) 
                {
                    cooldownQueue.push({maxHeap.top() - 1, cooldownTimestamp});
                }
                maxHeap.pop();
            }

            if (!cooldownQueue.empty() && currentCycle >= cooldownQueue.front().second) 
            {
                if (cooldownQueue.front().first > 0) 
                {
                    maxHeap.push(cooldownQueue.front().first);
                }
                cooldownQueue.pop();
            }
            currentCycle++;
        }
        return currentCycle;
    }
};
