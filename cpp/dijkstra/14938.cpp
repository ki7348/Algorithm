#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;
int n,m,r;
vector<pair<int,int>> graph[101];
int d[101];
vector<int> v;
vector<int> item;

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
    cin >> n >> m >> r;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<r;i++){
        int a, b, c ;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=n;i++){
        fill(d,d+101,INF);
        dijkstra(i);
        int temp = 0;
        for(int j=1;j<=n;j++){
            if(d[j] <= m){
                temp+=v[j];
            }
        }
        item.push_back(temp);
    }
    // for(int i=0;i<item.size();i++){
    //     cout << item[i] << ' ';
    // }    
    cout << *max_element(item.begin(),item.end()) << '\n';
}