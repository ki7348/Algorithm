#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
vector<pair<int,int>> graph[1001];
int d[1001];
int max_elem = 0;

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist){
            continue;
        }

        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost >= d[graph[now][i].first]){
                continue;
            }
            pq.push({cost, graph[now][i].first});
            d[graph[now][i].first] = cost;
        }
    }
}

int main() {
    int n,m,x;
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    for(int i=1;i<=n;i++){
        int value = 0;
        fill(d,d+1001,INF);
        dijkstra(i);
        value += d[x];
        fill(d,d+1001,INF);
        dijkstra(x);
        value += d[i];
        max_elem = max(max_elem, value);
    }

    cout << max_elem << '\n';
}