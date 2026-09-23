class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // every car acts as a blocker for the ones behind it, if its traveling at a slower speed.  
        // Therefore, we can consolidate groups of cars into just the single car in front of it, if we have a way to know
        // that the car will be blocked before getting there
        // calculation to tell how many ticks it will take for a car to get to the exit can be done through position + speed * x = target, where x is ticks
        // or converted, (target - position) / speed, rounded up
        // we can do a pass through the array to get the ticks needed for each car, that eliminates any annoying tracking of multiple nums (O(n))
        // If a car in front is going faster or same speed, we will never reach it, so its ticks will _always_ be faster
        // Might also want to sort by position here, since that's going to determine a lot of this
        // traverse backwards through the array, pushing each one into a vector<vector<int>> or a stack or something.
        // if you see a car behind you with <= ticks, add it to the index of the vector.
        // if you see a car behind you with greater ticks, that becomes the new bottleneck, so pushback another Vector<int> and start adding to that
        // return size of vector<int>, this approach is O(n + nlog(n)) because of the sort.  Faster ways to do this would remove the sort, or solve in a single pass
        // all values of position are unique, which means that we are supposed to use that as some sort of index, probably?

        unordered_map<int, int> positionSpeedIndex;
        vector<vector<int>> fleets;
        int currentFleetIndex = -1;
        float maxTicks = 0.0;
        for (int i = 0; i < position.size(); i++) 
        {
            positionSpeedIndex[position[i]] = speed[i];
        }
        sort(position.begin(), position.end(), std::greater<>());
        
        for (int i = 0; i < position.size(); i++) 
        {
            float convertedTime = (float)(target - position[i]) / (float)positionSpeedIndex[position[i]];
            if (convertedTime > maxTicks) 
            {
                maxTicks = convertedTime;
                fleets.push_back(vector<int>());
                currentFleetIndex++;
            }
            fleets[currentFleetIndex].push_back(position[i]);
        }
        return fleets.size();
    }
};
