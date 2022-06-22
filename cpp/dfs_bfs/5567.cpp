#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n,m;
vector<int> graph[501];
queue<int> q;
bool visited[501];
int dist[501];

int main () {
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    q.push({1});
    visited[1] = true;
    dist[1] = 0;
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
    int result = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] <= 2 && dist[i] > 0){
            result++;
        }
    }
    cout << result << '\n';
}