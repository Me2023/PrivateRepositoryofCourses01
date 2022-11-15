#include <iostream>
#include "Dijkstra.cpp"
using namespace std;

int main() {
    char v[5] = {'a','b','c','d','e'}; 
    int c[7] = {10, 30, 100, 50, 10, 20, 60};
    char ed[7][2] = {'a','b', 'a','d', 'a','e', 'b','c', 'c','e', 'd','c', 'd','e'};
    int i;
    vector<char> vertices; vector<int> weight;
    for (i = 0; i < 5; i++) {
        vertices.push_back(v[i]);
    }
    for (i = 0; i < 7; i++) {
        weight.push_back(c[i]);
    }
    
    MGraph<char, int> G(vertices, ed, weight, 5, 7, 1);
    G.printMGraph(1);
    cout << G.getValue(3) << " 的第一个邻接顶点是 " << G.getValue(G.firstNeighbor(3)) << endl;

    vector<int> dist;
    vector<int> path;
    ShortestPath(G, 1, dist, path);
    while(!dist.empty()) {
        cout << dist.back() << endl;
        dist.pop_back();
    }
    while(!path.empty()) {
        cout << path.back() << endl;
        path.pop_back();
    }
    printShortestPath(G, 1, dist, path);
}