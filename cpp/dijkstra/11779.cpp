#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
vector<pair<int,int>> graph[1001];
int prev_elem[1001];
int d[1001];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist > d[now]){
            continue;
        }

        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost >= d[graph[now][i].first]){
                continue;
            }
            d[graph[now][i].first] = cost;
            prev_elem[graph[now][i].first] = now;
            pq.push({cost, graph[now][i].first});
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    int start, end;
    cin >> start >> end;

    fill(d,d+1001,INF);
    dijkstra(start);
    cout << d[end] << '\n';
    
    vector<int> loc;
    int idx = end;
    loc.push_back(end);
    while(true){
        if(idx == start){
            break;
        }
        loc.push_back(prev_elem[idx]);
        idx = prev_elem[idx];
    }
    cout << loc.size() << '\n';
    for(int i=loc.size()-1;i>=0;i--){
        cout << loc[i] << ' ';
    }
    cout << '\n';
}