#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;
int t;
int d[101];

void dijkstra(int start, vector<pair<int,int>> graph[1001]){
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
    cin >> t;
    for(int i=0;i<t;i++){
        vector<pair<int,int>> graph[1001];
        int n,m;
        cin >> n >> m;
        for(int j=0;j<m;j++){
            int a,b,c;
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b,c));
            graph[b].push_back(make_pair(a,c));
        }
        int k;
        cin >> k;
        vector<int> v;
        int result[101] = {0,};
        for(int j=0;j<k;j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        for(int j=0;j<v.size();j++){
            fill(d,d+101,INF);
            dijkstra(v[j],graph);
            for(int j=1;j<=n;j++){
                result[j] += d[j];
            }
        }
        int min_elem = 99999;
        for(int j=1;j<=n;j++){
            min_elem = min(min_elem,result[j]);
        }
        for(int j=1;j<=n;j++){
            if(result[j] == min_elem){
                cout << j << '\n';
                break;
            }
        }
    }
}