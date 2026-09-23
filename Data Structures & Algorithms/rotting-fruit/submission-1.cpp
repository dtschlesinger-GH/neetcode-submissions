class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // We need the minimum here, so we need to do BFS
        // loop through and grab all 2 values, pushing them to the queue 
        // while we are looping, grab all 1 values and store them in a vector<pair<int, int>>, so we can check them later
        // BFS from all 2 points simultaniously, tracking time
        // if you hit a 1, set it to 2, and mark your time.  If you hit a 0, don't progress
        // once we finish the DFS, check every stored 1 fruit location in the updated grid.  If any are still 1, we return -1

        set<pair<int, int>> freshFruitLocations;
        map<pair<int, int>, int> timeToRotHash;
        queue<pair<int, int>> rottenFruitLocations;
        int maxTime = 0;
        int bfsPass = 0;

        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[0].size(); j++) 
            {
                if (grid[i][j] == 1) 
                {
                    freshFruitLocations.insert({i,j});
                }
                if (grid[i][j] == 2) 
                {
                    rottenFruitLocations.push({i,j});
                    grid[i][j] = 1;
                }
            }
        }
        
        while (!rottenFruitLocations.empty()) 
        {
            int bfsPassSize = rottenFruitLocations.size();
            for (int index = 0; index < bfsPassSize; index++) 
            {
                int row = rottenFruitLocations.front().first;
                int col = rottenFruitLocations.front().second;
                rottenFruitLocations.pop();

                if (grid[row][col] != 1) 
                {
                    continue;
                }

                grid[row][col] = 2;
                timeToRotHash[{row, col}] = bfsPass;

                // there's ways to optimize this by not pushing visited nodes on here, but like, whatever
                if (row > 0) 
                {
                    rottenFruitLocations.push({row-1, col});
                }
                if (row < grid.size() - 1) 
                {
                    rottenFruitLocations.push({row+1, col});
                }
                if (col > 0) 
                {
                    rottenFruitLocations.push({row, col-1});
                }
                if (col < grid[0].size() - 1) 
                {
                    rottenFruitLocations.push({row, col+1});
                }
            }
            bfsPass++;
        }

        for (const auto element : freshFruitLocations) 
        {
            if (grid[element.first][element.second] == 1) 
            {
                maxTime = -1;
                break;
            }
            else if (grid[element.first][element.second] == 2) 
            {
                maxTime = max(maxTime, timeToRotHash[{element.first, element.second}]);
            }
        }
        return maxTime;
    }
};
