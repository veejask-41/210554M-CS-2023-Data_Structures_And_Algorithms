#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int INF = 1e9;
const int MaxNode = 6;

vector<pair<int, int>> adjacencyMatrix[MaxNode];
bool vis[MaxNode];

int Prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int mst_cost = 0;
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        if(vis[u]) continue;
        mst_cost += p.first;
        vis[u] = true;
        for(auto pr : adjacencyMatrix[u]){
        int v = pr.first;
        int w = pr.second;
        if(!vis[v]){
            pq.push({w, v});
        }
        }
    }
    return mst_cost;
}

int main() {
    adjacencyMatrix[0].push_back({5, 1});
    adjacencyMatrix[0].push_back({1, 3});
    adjacencyMatrix[1].push_back({3, 1});
    adjacencyMatrix[1].push_back({0, 3});
    adjacencyMatrix[2].push_back({1, 2});
    adjacencyMatrix[1].push_back({2, 2});
    adjacencyMatrix[2].push_back({3, 3});
    adjacencyMatrix[2].push_back({5, 5});
    adjacencyMatrix[1].push_back({4, 10});
    adjacencyMatrix[3].push_back({2, 3});
    adjacencyMatrix[4].push_back({5, 4});
    adjacencyMatrix[3].push_back({1, 1});
    adjacencyMatrix[5].push_back({0, 1});
    adjacencyMatrix[4].push_back({1, 10});
    adjacencyMatrix[3].push_back({4, 5});
    adjacencyMatrix[5].push_back({4, 4});
    adjacencyMatrix[5].push_back({2, 5});
    adjacencyMatrix[4].push_back({3, 5});
    int mst_cost = Prim();
    cout << "MST cost : " << mst_cost << endl;
    return 0;
}