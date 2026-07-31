class Solution {
public:
    void dfs(vector<vector<int>>& img, int i, int j, int org_clr, int new_clr) {
        if (i < 0 || j < 0 || i >= img.size() || j >= img[0].size() ||
            img[i][j] != org_clr || img[i][j] == new_clr) {
            return;
        }

        img[i][j] = new_clr;
        dfs(img, i - 1, j, org_clr, new_clr);
        dfs(img, i, j - 1, org_clr, new_clr);
        dfs(img, i + 1, j, org_clr, new_clr);
        dfs(img, i, j + 1, org_clr, new_clr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int i = sr, j = sc;
        dfs(image, i, j, image[i][j], color);
        return image;
    }
};