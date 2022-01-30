#include <iostream>

using namespace std;

int n, m;
bool check[101] = {false};
int graph [101][101];
int result = 0;

void dfs(int v){
    check[v] = 1;
    result++;
    for(int i=1;i<=n;i++){
        if(!check[i] && graph[v][i] == 1){
            check[i] = 1;
            dfs(i);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    dfs(1);
    cout << result-1 << '\n';
}