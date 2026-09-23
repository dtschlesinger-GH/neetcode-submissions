class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> nodeInIndicies;
        unordered_map<int, vector<int>> adjacencyList;
        queue<int> khansQueue;
        vector<int> toReturn;
        for (int i = 0; i < prerequisites.size(); i++) 
        {
            nodeInIndicies[prerequisites[i][0]] += 1;
            adjacencyList[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        }

        for (int i = 0; i < numCourses; i++) 
        {
            if (nodeInIndicies[i] == 0) 
            {
                khansQueue.push(i);
            }
        }

        while (!khansQueue.empty()) 
        {
            int top = khansQueue.front();
            khansQueue.pop();
            nodeInIndicies.erase(top);
            toReturn.push_back(top);
            for (const int& neighbor : adjacencyList[top]) 
            {
                nodeInIndicies[neighbor] -= 1;
                if (nodeInIndicies[neighbor] == 0) 
                {
                    khansQueue.push(neighbor);
                }
            }
        }
        return nodeInIndicies.empty() ? toReturn : vector<int>();
    }
};
