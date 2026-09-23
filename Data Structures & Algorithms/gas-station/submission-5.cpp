class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // If sum of costs exceeds sum of gas, we don't even need to check, it fails
        // brute force would be to start at the gas station with the most gas, and then just go.
            // if you didn't make it, go to the next most, and so on and so forth
        // if we start at a local high point, then if we run out of gas, we know that any point within the trip
        // from that local high point is invalid, because we couldn't have started at a better point.  Therefore, 
        // we increment to the next station (the one we ran out of gas trying to reach, and start from there).
        // if we hit our initial station when simming a trip, we return our start
        // if we run out of valid stations, we return -1

        int gasCostTotal = 0;
        int maxStation = 0;
        int gasDiffMax = -10000;
        for (int i = 0; i < gas.size(); i++) 
        {
            int gasDiff = gas[i] - cost[i];
            gasCostTotal += gasDiff;
            if (gasDiff > gasDiffMax) 
            {
                gasDiffMax = gasDiff;
                maxStation = i;
            }
        }

        // there is more cost than gas available, we physically can't do the trip
        if (gasCostTotal < 0) 
        {
            return -1;
        }

        int numValidStations = gas.size();
        vector<int> stationsUsed;
        int startingStation = maxStation;
        cout << "starting from max station " << maxStation << endl;
        while (numValidStations > 0) 
        {
            stationsUsed.clear();
            int currentStation = startingStation;
            gasCostTotal = 0;
            while (gasCostTotal >= 0) 
            {
                stationsUsed.push_back(currentStation);
                gasCostTotal += gas[currentStation] - cost[currentStation];
                if (gasCostTotal >= 0) 
                {
                    currentStation = currentStation == gas.size() - 1 ? 0 : currentStation + 1;
                }
                if (currentStation == startingStation && gasCostTotal >= 0) 
                {
                    return startingStation;
                }
            }
            int temp = startingStation;
            numValidStations -= stationsUsed.size();
            startingStation = currentStation == gas.size() - 1 ? 0 : currentStation + 1;
            cout << "failed to reach from station " << temp << " using up " << stationsUsed.size() << ", restarting at station " << startingStation << endl;
        }
        return -1;
    }
};
