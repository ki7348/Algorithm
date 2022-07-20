#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9

using namespace std;
int n,m;
int graph[501][501]; 

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(graph[a-1][b-1] <= c){
            cout << "Enjoy other party" << '\n';
        } else {
            cout << "Stay here" << '\n';
        }
    }
}