#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

#define INF 1e9

using namespace std;
int n,m,a,b,c;
vector<pair<int,int>> graph[100001];
int d[100001];
vector<int> result;
int max_elem[100001];


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
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> m;
    for(int i=0;i<100001;i++){
        max_elem[i] = INF;
    }
    for(int i=0;i<m;i++){
        int g,e,l;
        cin >> g >> e >> l;
        graph[g].push_back(make_pair(e,l));
        graph[e].push_back(make_pair(g,l));
    }
    fill(d,d+100001,INF);
    dijkstra(a);
    for(int i=1;i<=n;i++){
        max_elem[i] = min(max_elem[i],d[i]);
    }
    fill(d,d+100001,INF);
    dijkstra(b);
    for(int i=1;i<=n;i++){
        max_elem[i] = min(max_elem[i],d[i]);
    }
    fill(d,d+100001,INF);
    dijkstra(c);
    for(int i=1;i<=n;i++){
        max_elem[i] = min(max_elem[i],d[i]);
    }
    int result = 0;
    for(int i=1;i<=n;i++){
        result = max(result,max_elem[i]);
    }
    for(int i=1;i<=n;i++){
        if(max_elem[i] == result){
            cout << i << '\n';
            return 0;
        }
    }
}