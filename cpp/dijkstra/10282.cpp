#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;
int t;
int d[10001];
// vector<pair<int,int>> graph[10001];

void dijkstra(int start,vector<pair<int,int>> graph[10001]){
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
        vector<pair<int,int>> graph[10001];
        int n,k,c;
        cin >> n >> k >> c;
        for(int j=0;j<k;j++){
            int a,b,s;
            cin >> a >> b >> s;
            graph[b].push_back(make_pair(a,s));
        }
        fill(d,d+10001,INF);
        dijkstra(c,graph);
        int count = 0;
        int max_num = 0;
        // for(int j=1;j<=n;j++)
        //     cout << d[j] << ' ';
        // cout << '\n';
        for(int j=1;j<=n;j++){
            if(d[j]==INF)
                continue;
            count++;
            max_num = max(max_num,d[j]);
        }
        cout << count << ' ' << max_num << '\n';
    }
    
}