#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int n,m;
int graph[501][501];

int main(){
    cin >> n >> m;
    for(int i=0;i<501;i++){
        fill(graph[i],graph[i]+501,INF);
    }

    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            if(a==b){
                graph[a][b] = 0;
            }
        }
    }

   for(int i=0;i<m;i++){
       int a,b;
       cin >> a >> b;
       graph[a][b] = 1;
   }

   for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(graph[i][j] == INF)
    //             cout << 0 << ' ';
    //         else
    //             cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int result = 0;
    for(int i=1;i<=n;i++){
        int temp = 0;
        for(int j=1;j<=n;j++){
            if(graph[i][j] != INF || graph[j][i] != INF){
                temp++;
            }
        }
        if(temp == n)
            result++;
    }
    cout << result << '\n';
}