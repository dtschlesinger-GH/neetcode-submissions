class KthLargest {
public:
    priority_queue<int, vector<int>, std::greater<int>> pQueue;
    int returnIndex;
    KthLargest(int k, vector<int>& nums) {
        returnIndex = k;
        for (const int element : nums) 
        {
            pQueue.push(element); 
            if (pQueue.size() > returnIndex) {
                pQueue.pop();
            }
        }
    }
    
    int add(int val) {
        pQueue.push(val);
        if (pQueue.size() > returnIndex) 
        {
            pQueue.pop();
        }
        return pQueue.top();
    }
};
