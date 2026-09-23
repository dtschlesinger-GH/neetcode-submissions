class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> toReturn(temperatures.size(), 0);
        stack<pair<int, int>> temps;

        for (int i = 0; i < temperatures.size(); i++) 
        {
            int t = temperatures[i];
            while (!temps.empty() && t > temps.top().first) 
            {
                const pair<int, int>& top = temps.top();
                temps.pop();
                toReturn[top.second] = i - top.second;
            }
            temps.push({t, i});
        }
        return toReturn;
    }
};
