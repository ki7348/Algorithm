#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
bool check[1001] = {false};
int graph [1001][1001];
queue<int> q;

void dfs(int v){
    cout << v << ' ';
    for(int i=1;i<=n;i++){
        if(!check[i] && graph[v][i] == 1){
            check[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int v){
    q.push(v);
    check[v] = 1;
    while(!q.empty()){
        v = q.front();
        q.pop();
        cout << v << ' ';
        for(int i=1;i<=n;i++){
            if(!check[i] && graph[v][i] == 1){
                check[i] = 1;
                q.push(i);
            }
        }
    }
}


int main(){
    cin >> n >> m >> v;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    check[v] = 1;
    dfs(v);
    cout << '\n';
    for(int i=1;i<1001;i++){
        check[i] = false;
    }
    bfs(v);
    cout << '\n';
}