#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;
int v,e,k;
vector<pair<int,int>> graph[20001];
int d[20001];

void dijkstra(int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now]<dist)
            continue;
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(cost,graph[now][i].first));
            }
        }
    }
}

int main(){
    cin >> v >> e >> k;
    for(int i=0;i<e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }
    fill(d,d+20001,INF);
    dijkstra(k);
    for(int i=1;i<=v;i++){
        if(d[i] == INF)
            cout << "INF" << '\n';
        else
            cout << d[i] << ' ' << '\n';
    }
    
}