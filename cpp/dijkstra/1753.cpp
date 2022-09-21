#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
vector<pair<int,int>> graph[20001];
int d[20001];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()){
        int dest = pq.top().first;
        int target = pq.top().second;
        pq.pop();

        for(int i=0;i<graph[target].size();i++){
            int len = dest + graph[target][i].second;
            if(len > d[graph[target][i].first]){
                continue;
            }
            d[graph[target][i].first] = len;
            pq.push({len, graph[target][i].first});
        }
    }

}

int main(){
    int v,e;
    cin >> v >> e;
    int start;
    cin >> start;

    for(int i=0;i<e;i++){
        int x,y,z;
        cin >> x >> y >> z;
        graph[x].push_back({y,z});
    }

    fill(d,d+20001,INF);
    dijkstra(start);

    for(int i=1;i<=v;i++){
        if(d[i] == INF){
            cout << "INF" << '\n';
        } else {
            cout << d[i] << '\n';
        }
    }
}