class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int>md(n, INT_MAX);
        vector<int>vis(n, 0);

        md[0] = 0;
        int tc = 0;

        for(int l = 0; l < n; l++){
            int u = -1;

            for(int i = 0; i < n; i++){
                if(!vis[i] && (u == -1 || md[i] < md[u])){
                    u = i;
                }
            }

            vis[u] = 1;
            tc += md[u];

            for(int v = 0; v < n; v++){
                if(!vis[v]){
                    int cst = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

                    md[v] = min(md[v], cst);
                }
            }
        }
        return tc;
    }
};