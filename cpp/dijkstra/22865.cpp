#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;
int n;
int a,b,c;
int m;
vector<pair<int,int>> graph[100001];
vector<pair<int,int>> result;
int d[100001];
int d2[100001];
int d3[100001];
int min_elem_list[100001];

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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> m;
    vector<int> fr;
    fr.push_back(a);
    fr.push_back(b);
    fr.push_back(c);
    for(int i=0;i<m;i++) {
        int q,w,e;
        cin >> q >> w >> e;
        graph[q].push_back(make_pair(w,e));
        graph[w].push_back(make_pair(q,e));
    }
    vector<int> v;
    fill(d,d+100001,INF);
    dijkstra(a);
    fill(d2,d2+100001,INF);
    dijkstra(b);
    fill(d3,d3+100001,INF);
    dijkstra(c);
    for(int i=0;i<100001;i++) {
        int min_elem = d[i] > d2[i] ? d2[i] : d[i];
        min_elem = min(min_elem, d3[i]);
        min_elem_list[i] = min_elem;
    }
    int result = 0;
    int val = 0;
    for(int i=1;i<=n;i++) {
        if(min_elem_list[i] > result) { 
            result = min_elem_list[i];
            val = i;
        }
    }
    cout << val << '\n';
}