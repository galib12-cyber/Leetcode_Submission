class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(source);
        vis[source] = 1;

        while (q.empty() == false) {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for(int neigh : adj[node]){
                if(vis[neigh] == 0){
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }

        return false;
    }
};