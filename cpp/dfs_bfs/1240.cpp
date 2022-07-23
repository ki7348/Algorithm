#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
int n,m;
vector<pair<int,int>> graph[1001];
int dist[1001];

int bfs(int start, int end){
    queue<int> q;
    q.push(start);
    bool visited[1001] = {false,};
    dist[start] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int val = graph[cur][i].second;
            if(visited[next]){
                continue;
            }
            dist[next] = dist[cur] + val;
            q.push(next);
            visited[next] = true;
        }
    }
    return dist[end];
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cout << bfs(a,b) << '\n';
    }
}