class Solution {
public:
    void dfs(int i, int j, int vis[500][500], vector<vector<char>>& grid, int m,
             int n) {

        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == 1 ||
            grid[i][j] == '0') {
            return;
        }

        vis[i][j] = 1;

        dfs(i - 1, j, vis, grid, m, n);
        dfs(i, j - 1, vis, grid, m, n);
        dfs(i + 1, j, vis, grid, m, n);
        dfs(i, j + 1, vis, grid, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        int arr[500][500] = {};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && arr[i][j] == 0) {
                    dfs(i, j, arr, grid, m, n);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};