class Solution {
public:
    vector<vector<int>> toReturn;

     void dfs(int idx, vector<int> path, int cur, vector<int>& candidates, int target) {
        if (cur == target) {
            toReturn.push_back(path);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (cur + candidates[i] > target) {
                break;
            }

            path.push_back(candidates[i]);
            dfs(i + 1, path, cur + candidates[i], candidates, target);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> currentSubset;

        dfs(0, {}, 0, candidates, target);

        return toReturn;
    }
};
