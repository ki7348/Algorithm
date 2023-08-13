#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int,int>> graph[20001];
int d[20001];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist){
            continue;
        }

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int cost = dist + graph[now][i].second;
            if(cost < d[next]){
                d[next] = cost;
                pq.push({cost, next});
            }
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;
    int k;
    cin >> k;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >>c ;
        graph[a].push_back({b,c});
    }
    fill(d,d+20001,INF);
    dijkstra(k);
    for(int i=1;i<=v;i++){
        if(d[i] == INF){
            cout << "INF" << '\n';
            continue;
        }
        cout << d[i] << '\n';
    }
}