class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);  // Initialize all colors to -1
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {  // If not visited
                if (!bfs(i, graph, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& colors) {
        queue<int> q;
        colors[start] = 0;  // Start coloring with 0
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int adjNode : graph[node]) {
                if (colors[adjNode] == -1) {  // If not colored
                    colors[adjNode] = (colors[node] == 1) ? 0 : 1;  // Alternate the color
                    q.push(adjNode);
                } else if (colors[adjNode] == colors[node]) {  // Same color as the current node
                    return false;
                }
            }
        }
        return true;
    }
};