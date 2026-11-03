#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> * l;
public:
    Graph(int v) {
        this->V = v;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    void print() {
        for(int i = 0; i < V; i++) {
            cout << i << " : ";
            for(auto x : l[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    void bfs() {
        
        queue <int> q;
        vector <bool> visited (V, false);
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            cout << curr << " ";
            list <int> neighbors = l[curr];

            for(int v : neighbors) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }

        }
    }
};
 int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    g.bfs();
}