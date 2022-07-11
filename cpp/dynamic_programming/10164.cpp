#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m,k;
int graph[16][16];
int d[16][16];

int main() {
    cin >> n >> m >> k;
    int idx = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            graph[i][j] = idx;
            idx++;
        }
    }
    d[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i == 1 && j == 1){
                continue;
            }
            d[i][j] = d[i-1][j] + d[i][j-1];
        }
    }
    int x = 0, y = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(graph[i][j] == k){
                x = i;
                y = j;
            }
        }
    }
    if(k == 0){
        cout << d[n][m] << '\n';
        return 0;
    }
    cout <<  d[x][y] * d[n-x+1][m-y+1] << '\n';
}