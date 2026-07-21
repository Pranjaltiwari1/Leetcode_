class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dest, unordered_set<string>& vis, double product) {
        if (src == dest) return product;

        vis.insert(src);

        for (auto& [next, weight] : graph[src]) {
            if (!vis.count(next)) {
                double ans = dfs(next, dest, vis, product * weight);
                if (ans != -1.0)
                    return ans;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];

            graph[u].push_back({v, w});
            graph[v].push_back({u, 1.0 / w});
        }

        vector<double> ans;

        for (auto& q : queries) {
            string src = q[0];
            string dest = q[1];

            if (!graph.count(src) || !graph.count(dest)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;
            ans.push_back(dfs(src, dest, vis, 1.0));
        }

        return ans;
    }
};