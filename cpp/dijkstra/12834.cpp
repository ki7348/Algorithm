#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;
int n,v,e;
int a,b;
vector<pair<int,int>> graph[1001];
int d[1001];
vector<int> team;


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
    cin >> n >> v >> e;
    cin >> a >> b;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        team.push_back(x);
    }
    for(int i=0;i<e;i++){
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y,z));
        graph[y].push_back(make_pair(x,z));
    }
    int result = 0;
    for(int i=0;i<team.size();i++){
        fill(d,d+1001,INF);
        dijkstra(team[i]);
        if(d[a]==INF){
            result+=-1;
        }else{
            result+=d[a];
        }
        if(d[b]==INF){
            result+=-1;
        }else{
            result+=d[b];
        }
    }
    cout << result << '\n';
}