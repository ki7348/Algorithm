#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int graph[1001][3];
int d[1001][3];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    d[1][0] = graph[1][0];
    d[1][1] = graph[1][1];
    d[1][2] = graph[1][2];
    for(int i=2;i<=n;i++){
        d[i][0] = min(d[i-1][1]+graph[i][0],d[i-1][2]+graph[i][0]);
        d[i][1] = min(d[i-1][0]+graph[i][1],d[i-1][2]+graph[i][1]);
        d[i][2] = min(d[i-1][0]+graph[i][2],d[i-1][1]+graph[i][2]);
    }   
    int result = d[n][0];
    for(int i=1;i<=2;i++){
        result = min(result,d[n][i]);
    }
    cout << result << '\n';
}