class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, std::less<int>> maxHeap;
        
        for (const int element : stones) 
        {
            maxHeap.push(element);
        }

        while (maxHeap.size() > 1) 
        {
            int firstStone = maxHeap.top();
            maxHeap.pop();
            int secondStone = maxHeap.top();
            maxHeap.pop();
            int remainingWeight = abs(firstStone - secondStone);
            if (remainingWeight > 0) 
            {
                maxHeap.push(remainingWeight);
            }
        }
        return maxHeap.size() > 0 ? maxHeap.top() : 0;
    }
};
