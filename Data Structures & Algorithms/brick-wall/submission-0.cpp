class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> seams;
        int maxSeams = 0;

        for (int row = 0; row < wall.size(); row++) 
        {
            int prefixSum = 0;
            for (int brickCount = 0; brickCount < wall[row].size(); brickCount++) 
            {
                if (brickCount == wall[row].size() - 1) {continue;}
                prefixSum += wall[row][brickCount];
                seams[prefixSum] += 1;
                //cout << "Incrementing Prefix sum at " << prefixSum <<", count is now " << seams[prefixSum] << endl;
                maxSeams = max(maxSeams, seams[prefixSum]);
            }
        }
        return wall.size() - maxSeams;
    }
};