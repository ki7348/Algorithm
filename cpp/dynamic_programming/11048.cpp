#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int graph[1001][1001];
int d[1001][1001];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    d[1][1] = graph[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1){
                continue;
            }
            d[i][j] = graph[i][j] + max(d[i-1][j],d[i][j-1]);
        }
    }
    cout << d[n][m] << '\n';
}