#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;
int n,m,k,x;
vector<pair<int,int>> graph[300001];
int d[300001];
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
    cin >> n >> m >> k >> x;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(make_pair(b,1));
    }
    fill(d,d+300001,INF);
    dijkstra(x);
    for(int i=1;i<=n;i++){
        if(d[i] == k)
            v.push_back(i);
    }
    if(v.size()==0){
        cout << -1 << '\n';
        return 0;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << '\n';
    }
    
    
}