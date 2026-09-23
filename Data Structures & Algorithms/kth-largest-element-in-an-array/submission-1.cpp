class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> minHeap;

        for (const int& element : nums) 
        {
            minHeap.push(element);
            if (minHeap.size() > k) 
            {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
