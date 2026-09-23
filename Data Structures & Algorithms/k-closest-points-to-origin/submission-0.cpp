class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto minHeapComp = [](const pair<pair<int, int>, int>& lhs, const pair<pair<int, int>, int>& rhs) {return lhs.second < rhs.second;};
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(minHeapComp)> minHeap(minHeapComp);
        
        for (int i = 0; i < points.size(); i++) 
        {
            int distSquared = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            minHeap.push({{points[i][0], points[i][1]}, distSquared});
            if (minHeap.size() > k) 
            {
                minHeap.pop();
            }
        }

        vector<vector<int>> toReturn;
        while (!minHeap.empty()) 
        {
            const pair<pair<int, int>, int>& element = minHeap.top();
            vector<int> point;
            point.push_back(element.first.first);
            point.push_back(element.first.second);
            toReturn.push_back(point);
            minHeap.pop();
        }
        return toReturn;
    }
};
