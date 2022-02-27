#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int graph[1025][1025];
int d[1025][1025];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>graph[i][j];
            d[i][j] = d[i-1][j]+d[i][j-1] - d[i-1][j-1]+graph[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c,e;
        cin >> a >> b >> c >> e;
        cout << d[c][e] - d[c][b-1] - d[a-1][e] + d[a-1][b-1] << '\n';
    }
}