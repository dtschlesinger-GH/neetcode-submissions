class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<int, vector<int>, std::greater<int>> passengersInCar;
        int location = 0;
        int tripIndex = 0;

        auto sortFunc = [](vector<int> left, vector<int> right) { return left[1] < right[1];};
        sort(trips.begin(), trips.end(), sortFunc);
        location = trips[0][1];

        for (; location < 1001; location++) 
        {
            while (tripIndex < trips.size() && trips[tripIndex][1] == location) 
            {
                //cout << "adding " << trips[tripIndex][0] << " people at location " << trips[tripIndex][1] << " to be dropped off at " << trips[tripIndex][2] << endl;
                for (int j = 0; j < trips[tripIndex][0]; j++) 
                {
                    passengersInCar.push(trips[tripIndex][2]);
                }
                tripIndex++;
            }
            if (!passengersInCar.empty())
            {
                int tripDest = passengersInCar.top();
                while (tripDest == location && !passengersInCar.empty()) 
                {
                    passengersInCar.pop();
                    tripDest = passengersInCar.top();
                }
            }

            if (passengersInCar.size() > capacity) 
            {
                return false;
            }
        }
        return true;
    }
};