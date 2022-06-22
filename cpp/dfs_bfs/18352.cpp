#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n,m,k,x;
vector<int> graph[300001];
queue<int> q;
bool visited[300001];
int dist[300001];

int main () {
    cin >> n >> m >> k >> x;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    q.push({x});
    visited[x] = true;
    dist[x] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                dist[next] = dist[cur] + 1;
            }
        }
    }
    bool state = false;
    for(int i=1;i<=n;i++){
        if(dist[i] == k){
            cout << i << '\n';
            state = true;
        }
    }
    if(!state){
        cout << -1 << '\n';
    }
}