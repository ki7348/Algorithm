#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Vector {
    int s,x,y;
};

int n,t;
int graph[1001][1001];
vector<Vector> v;

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> t;
    v.push_back({0,0,0});
    for(int i=1;i<=n;i++){
        int s,x,y;
        cin >> s >> x >> y;
        v.push_back({s,x,y});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                graph[i][j] = 0;
            }
            if(v[i].s == 1 && v[j].s == 1){
                graph[i][j] = min(t,abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y));
            } else {
                graph[i][j] = abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cout << graph[a][b] << '\n';
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}