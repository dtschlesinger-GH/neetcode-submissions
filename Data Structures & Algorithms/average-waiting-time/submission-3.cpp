class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long customerCount = customers.size();
        long totalTimeWaiting = 0;
        int currentFinishTime = 0;
        int currentTime = 0;

        for (const vector<int> customer : customers) 
        {
            const int& arrivalTime = customer[0];
            const int& prepTime = customer[1];

            currentFinishTime = max(currentFinishTime + prepTime, arrivalTime + prepTime);
            totalTimeWaiting += currentFinishTime - arrivalTime;
        }

        return ((double)totalTimeWaiting / (double)customerCount);
    }
};