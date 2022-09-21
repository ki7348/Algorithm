#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

vector<pair<int,int>> graph[1001];
int d[1001];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    d[start] = 0;

    while(!pq.empty()){
        int dist = pq.top().first;
        int target = pq.top().second;
        pq.pop();

        if(d[target] < dist){
            continue;
        }

        for(int i=0;i<graph[target].size();i++){
            int len = dist + graph[target][i].second;
            if(d[graph[target][i].first] <= len){
                continue;
            }
            d[graph[target][i].first] = len;
            pq.push({len, graph[target][i].first}); 
        }
    }

}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
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
}