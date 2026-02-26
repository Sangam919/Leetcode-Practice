class Solution {
public:
    void dfs(int n, vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to: graph[v]) {
            if (!visited[to]) dfs(n, graph, to, visited);
        }
    } 
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        bool res = false;
        vector<int> visited(n, 0);

        vector<vector<int>> graph(n);
        for (auto &edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(n, graph, source, visited);
        if (visited[destination] == 1) res = true;

        return res;
    }
};