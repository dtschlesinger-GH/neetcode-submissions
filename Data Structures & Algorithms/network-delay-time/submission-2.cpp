class Solution {
public:
    int SPFA(vector<vector<int>>& times, int n, int k) {
        // This is the implementation I came up with from scratch, its good, just not as good as Dijkstra's
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

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (const auto& time : times) 
        {
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        set<int> visited;
        int t = 0;
        minHeap.push({0,k});

        while(!minHeap.empty()) 
        {
            pair<int, int> currentNode = minHeap.top();
            minHeap.pop();
            if (visited.contains(currentNode.second)) 
            {
                continue;
            }
            visited.insert(currentNode.second);
            t = currentNode.first;

            if (edges.contains(currentNode.second)) 
            {
                for (const auto& neighbors : edges[currentNode.second]) 
                {
                    if (!visited.contains(neighbors.first)) 
                    {
                        minHeap.push({currentNode.first + neighbors.second, neighbors.first});
                    }
                }
            }
        }
        return visited.size() == n ? t : -1;
    }
};
