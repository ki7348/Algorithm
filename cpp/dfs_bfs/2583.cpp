#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,k;
int graph[101][101];
bool check[101][101];
int cnt = 0;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int,int>> q;
vector<int> v;

int bfs(int x, int y){
    q.push(make_pair(x,y));
    check[x][y] = 1;
    int temp = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(!check[dx][dy] && graph[dx][dy]==0){
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
                temp++;
            }
        }
    }
    return temp;
}

int main(){
    cin >> n >> m >> k;
    for(int t=0;t<k;t++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int i=b;i<d;i++){
            for(int j=a;j<c;j++){
                graph[i][j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==0 && !check[i][j]){
                v.push_back(bfs(i,j));
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << ' '; 
    }
}