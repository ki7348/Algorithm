#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;
int n,m;
vector<pair<int,int>>graph[201];
int d[201];
int result[201][201];

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
                if(result[start][now]==0){
                    result[start][graph[now][i].first] = graph[now][i].first;
                }else{
                    result[start][graph[now][i].first] = result[start][now];
                }
                d[graph[now][i].first] = cost;
                pq.push(make_pair(cost,graph[now][i].first));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++){
        fill(d,d+201,INF);
        dijkstra(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                cout << '-' << ' ';
            }else{
                cout << result[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}