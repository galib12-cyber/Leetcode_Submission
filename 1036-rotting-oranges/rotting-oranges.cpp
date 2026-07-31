class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int vis[100][100] = {};
        int r = 0;
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        while (q.size() > 0) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;

            q.pop();

            r = max(r, t);

            if (i - 1 >= 0 && vis[i - 1][j] == 0 && grid[i - 1][j] == 1) {
                q.push({{i - 1, j}, t + 1});
                vis[i - 1][j] = 1;
            }

            if (j + 1 < n && vis[i][j + 1] == 0 && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, t + 1});
                vis[i][j + 1] = 1;
            }

            if (i + 1 < m && vis[i + 1][j] == 0 && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, t + 1});
                vis[i + 1][j] = 1;
            }

            if (j - 1 >= 0 && vis[i][j - 1] == 0 && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, t + 1});
                vis[i][j - 1] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    return -1;
                }
            }
        }

        return r;
    }
};

//  2 1 1 1 1 0 0 1 1