#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;
int n,e,k,x;
vector<pair<int,int>> graph[801];
int d[801];
vector<int> v;

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
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    fill(d,d+801,INF);
    int v1,v2;
    cin >> v1 >> v2;
    dijkstra(1);
    int first = d[v1];
    fill(d,d+801,INF);
    dijkstra(v1);
    int second = d[v2];
    fill(d,d+801,INF);
    dijkstra(v2);
    int third = d[n];
    if(first==INF || second==INF || third==INF){
        cout << -1 << '\n';
        return 0;
    }
    fill(d,d+801,INF);
    dijkstra(1);
    int new_first = d[v2];
    fill(d,d+801,INF);
    dijkstra(v2);
    int new_second = d[v1];
    fill(d,d+801,INF);
    dijkstra(v1);
    int new_third = d[n];
    cout << min(first + second + third,new_first+new_second+new_third) << '\n';
    
    
}