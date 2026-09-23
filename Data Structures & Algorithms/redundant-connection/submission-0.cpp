class Solution {
    vector<bool> visit;
    vector<vector<int>> adj;
    unordered_set<int> cycle;
    int cycleStart;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visit.resize(n + 1, false);
        cycleStart = -1;
        dfs(1, -1);

        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (cycle.count(u) && cycle.count(v)) {
                return {u, v};
            }
        }
        return {};
    }

private:
    bool dfs(int node, int par) {
        if (visit[node]) {
            cycleStart = node;
            return true;
        }
        visit[node] = true;
        for (int nei : adj[node]) {
            if (nei == par) continue;
            if (dfs(nei, node)) {
                if (cycleStart != -1) cycle.insert(node);
                if (node == cycleStart) {
                    cycleStart = -1;
                }
                return true;
            }
        }
        return false;
    }
};