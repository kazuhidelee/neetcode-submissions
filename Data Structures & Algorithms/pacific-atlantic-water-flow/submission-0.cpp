class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> reachable(m, vector<int>(n, 0));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> res;

        // Mark pacific and atlantic starting cells only once
        for (int i = 0; i < m; ++i) {
            // pacific
            if (pacific[i][0] == 0) {
                queue<pair<int, int>> bfs;
                bfs.push({i, 0});
                pacific[i][0] = 1;
                reachable[i][0]++;
                while (!bfs.empty()) {
                    auto curr = bfs.front(); bfs.pop();
                    for (auto dir : directions) {
                        int x = curr.first + dir.first;
                        int y = curr.second + dir.second;
                        if (x >= 0 && y >= 0 && x < m && y < n &&
                            pacific[x][y] == 0 &&
                            heights[x][y] >= heights[curr.first][curr.second]) {
                            bfs.push({x, y});
                            pacific[x][y] = 1;
                            reachable[x][y]++;
                        }
                    }
                }
            }

            // atlantic
            if (atlantic[i][n - 1] == 0) {
                queue<pair<int, int>> bfs;
                bfs.push({i, n - 1});
                atlantic[i][n - 1] = 1;
                reachable[i][n - 1]++;
                while (!bfs.empty()) {
                    auto curr = bfs.front(); bfs.pop();
                    for (auto dir : directions) {
                        int x = curr.first + dir.first;
                        int y = curr.second + dir.second;
                        if (x >= 0 && y >= 0 && x < m && y < n &&
                            atlantic[x][y] == 0 &&
                            heights[x][y] >= heights[curr.first][curr.second]) {
                            bfs.push({x, y});
                            atlantic[x][y] = 1;
                            reachable[x][y]++;
                        }
                    }
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            // pacific
            if (pacific[0][j] == 0) {
                queue<pair<int, int>> bfs;
                bfs.push({0, j});
                pacific[0][j] = 1;
                reachable[0][j]++;
                while (!bfs.empty()) {
                    auto curr = bfs.front(); bfs.pop();
                    for (auto dir : directions) {
                        int x = curr.first + dir.first;
                        int y = curr.second + dir.second;
                        if (x >= 0 && y >= 0 && x < m && y < n &&
                            pacific[x][y] == 0 &&
                            heights[x][y] >= heights[curr.first][curr.second]) {
                            bfs.push({x, y});
                            pacific[x][y] = 1;
                            reachable[x][y]++;
                        }
                    }
                }
            }

            // atlantic
            if (atlantic[m - 1][j] == 0) {
                queue<pair<int, int>> bfs;
                bfs.push({m - 1, j});
                atlantic[m - 1][j] = 1;
                reachable[m - 1][j]++;
                while (!bfs.empty()) {
                    auto curr = bfs.front(); bfs.pop();
                    for (auto dir : directions) {
                        int x = curr.first + dir.first;
                        int y = curr.second + dir.second;
                        if (x >= 0 && y >= 0 && x < m && y < n &&
                            atlantic[x][y] == 0 &&
                            heights[x][y] >= heights[curr.first][curr.second]) {
                            bfs.push({x, y});
                            atlantic[x][y] = 1;
                            reachable[x][y]++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachable[i][j] == 2) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
