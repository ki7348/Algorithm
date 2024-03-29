#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e12

using namespace std;
int n,m;
vector<int> sight;
vector<pair<long long,long long>> graph[100001];
long long d[100001];

void dijkstra(int start){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,start});
    d[start] = 0;
    while(!pq.empty()){
        long long dist = pq.top().first;
        long long now = pq.top().second;
        pq.pop();
        if(d[now]<dist)
            continue;
        for(int i=0;i<graph[now].size();i++){
            long long cost = dist + graph[now][i].second;
            if(graph[now][i].first != n-1 && sight[graph[now][i].first] == 1){
                continue;
            }
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(cost,graph[now][i].first));
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        sight.push_back(x);
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    fill(d,d+100001,INF);
    dijkstra(0);
    // for(int i=0;i<n;i++){
    //     cout << d[i] << ' ';
    // }cout << '\n';
    if(d[n-1]!=INF){
    cout << d[n-1] << '\n';
    }else{
        cout << -1 << '\n';
    }
}