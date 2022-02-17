#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;
int n,m,x;
vector<pair<int,int>> graph[1001];
int d[1001];
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
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }
    for(int i=1;i<=n;i++){
        fill(d,d+1001,INF);
        dijkstra(i);
        int first = d[x];
        fill(d,d+1001,INF);
        dijkstra(x);
        v.push_back(first+d[i]);
    }
    int result = 0;
    for(int i=0;i<v.size();i++)
        result = max(result,v[i]);
    cout << result << '\n';
    
}