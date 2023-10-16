#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9

using namespace std;

int graph[301][301];

int main(){
    int n, m, t;
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			graph[i][j] = INF;
		}
	}

    for(int i=0;i<m;i++){
        int u,v,h;
        cin >> u >> v >> h;
        graph[u][v] = h;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j] = min(graph[i][j], max(graph[i][k],graph[k][j]));
            }
        }
    }

    for(int i=0;i<t;i++){
        int x,y;
        cin >> x >> y;
        if(graph[x][y] == INF){
            cout << -1 << '\n';
            continue;
        }
        cout << graph[x][y] << '\n';
    }
}