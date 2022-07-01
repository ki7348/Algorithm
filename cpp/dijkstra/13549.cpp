#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int n,k;
int graph[100001];
int d[100001];

void dijkstra(int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(now == k){
            break;
        }
        if(d[now]<dist)
            continue;
        int cost = dist + 1;
        if(cost < d[now-1]){
            d[now-1] = cost;
            pq.push(make_pair(cost,now-1));
        }
        int cost2 = dist + 1;
        if(cost2 < d[now+1]){
            d[now+1] = cost2;
            pq.push(make_pair(cost2,now+1));
        }
        int cost3 = dist;
        if(cost3 < d[now*2]){
            d[now*2] = cost3;
            pq.push(make_pair(cost3,now*2));
        }
    }
}

int main() {
    cin >> n >> k;
    fill(d,d+100001,INF);
    dijkstra(n);
    // for(int i=n;i<=k;i++){
    //     cout << d[i] << ' ';
    // }
    cout << d[k] << '\n';
}