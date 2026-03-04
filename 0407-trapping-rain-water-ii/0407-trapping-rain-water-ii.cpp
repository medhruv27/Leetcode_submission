#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int m = height.size(), n = height[0].size();
        if (m < 3 || n < 3) return 0; // Need at least a 3x3 to trap anything

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the Min-Heap
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({height[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int totalWater = 0;
        int currentMax = 0;
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int h = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            // The 'water level' is determined by the lowest wall we've encountered
            currentMax = max(currentMax, h);

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // If neighbor is lower than currentMax, it traps water
                    if (height[nr][nc] < currentMax) {
                        totalWater += (currentMax - height[nr][nc]);
                    }
                    pq.push({height[nr][nc], {nr, nc}});
                }
            }
        }
        return totalWater;
    }
};