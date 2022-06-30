#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
int n,m;
vector<pair<int,int>> graph[1001];
int current[1001];
int d[1001];

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
                current[graph[now][i].first] = now;
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
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    int start,end;
    cin >> start >> end;
    fill(d,d+1001,INF);
    dijkstra(start);
    cout << d[end] << '\n';

    vector<int> result;
    result.push_back(end);
    while(current[end] != 0){
        result.push_back(current[end]);
        end = current[end];
    }
    cout << result.size() << '\n';
    for(int i=result.size()-1;i>=0;i--){
        cout << result[i] << ' ';
    }
    cout << '\n';
}