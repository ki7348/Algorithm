#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int a, b;
int m;
int graph[101][101];
int check[101];
queue<int> q;

void bfs(int x){
    q.push(x);
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(graph[x][i]!=0 && !check[i]){
                q.push(i);
                check[i] = check[x]+1;
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    bfs(a);
    if(check[b]==0)
        cout << -1 << '\n';
    else
        cout << check[b] << '\n';
    
} 