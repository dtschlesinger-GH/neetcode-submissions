class Solution {
public:
    const bool DFS(const int& curCourse, map<int, vector<int>>& prereqMap, unordered_set<int> visited) 
    {
        if (prereqMap[curCourse].empty()) 
        {
            return true;
        }

        if (visited.contains(curCourse)) 
        {
            return false;
        }
        visited.insert(curCourse);

        for (const int neighbor : prereqMap[curCourse]) 
        {            
            if (!DFS(neighbor, prereqMap, visited)) 
            {
                return false;
            }
        }
        prereqMap[curCourse].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> courseToPrereq;
        unordered_set<int> coursesVisited;

        for (int i = 0; i < prerequisites.size(); i++) 
        {
            courseToPrereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i <= numCourses; i++) 
        {
            coursesVisited.clear();
            if (!DFS(i, courseToPrereq, coursesVisited)) 
            {
                return false;
            }
        }
        return true;
    }
};
