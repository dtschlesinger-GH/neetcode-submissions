class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graphTravelTimes;
        vector<int> minArrivalTimes(n + 1, 9999999);
        minArrivalTimes[0] = 0;
        queue<int> nodesVisited;

        if (n == 1) {return 0;}

        //start by making map of edges
        for (const vector<int>& element : times) 
        {
            graphTravelTimes[element[0]].push_back({element[1], element[2]});    
        }
        minArrivalTimes[k] = 0;
        nodesVisited.push(k);

        while (!nodesVisited.empty()) 
        {
            int currentNode = nodesVisited.front();
            nodesVisited.pop();
            int currentTime = minArrivalTimes[currentNode];
            cout << "arrived at node " << currentNode << " in time " << currentTime << endl;
            for (pair<int, int> edge : graphTravelTimes[currentNode]) 
            {
                int arrivalTime = currentTime + edge.second;
                cout << "Traveling to node " << edge.first << " in time " << arrivalTime << " with that node's current arrival time being " << minArrivalTimes[edge.first] << endl;

                if (minArrivalTimes[edge.first] > arrivalTime) 
                {
                    minArrivalTimes[edge.first] = arrivalTime;
                    nodesVisited.push(edge.first);
                }
            }
        }

        int totalTime = 0;
        for (int i = 0; i < minArrivalTimes.size(); i++) 
        {
            // if we never visited the node after BFS, its unreachable
            if (minArrivalTimes[i] == 9999999) 
            {
                return -1;
            }
            ////cout << "arrived at node " << i << " in time " << minArrivalTimes[i] << endl;
            //totalTime += minArrivalTimes[i];
            totalTime = max(totalTime, minArrivalTimes[i]);
        }
        return totalTime;
    }
};
