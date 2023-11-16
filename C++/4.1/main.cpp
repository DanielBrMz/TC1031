#include<bits/stdc++.h>

class Graph {
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::vector<int>> adjList;

public:
    void loadGraph(int n, int m) {
        adjMatrix.resize(n, std::vector<int>(n, 0));
        adjList.resize(n);

        for(int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adjMatrix[u][v] = 1;
            adjList[u].push_back(v);
        }
    }

    void DFS(int node, std::vector<bool>& visited) {
        visited[node] = true;
        std::cout << node << " ";

        for(int i = 0; i < adjMatrix[node].size(); i++) {
            if(adjMatrix[node][i] && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void BFS(int start) {
        std::vector<bool> visited(adjList.size(), false);
        std::queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";

            for(auto& adj : adjList[node]) {
                if(!visited[adj]) {
                    q.push(adj);
                    visited[adj] = true;
                }
            }
        }
    }
};

int main() {
    Graph g;
    int n, m;
    std::cin >> n >> m;
    g.loadGraph(n, m);

    std::vector<bool> visited(n, false);
    g.DFS(0, visited);
    std::cout << std::endl;

    g.BFS(0);
    std::cout << std::endl;

    return 0;
}
