#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,k;
int graph[201][201];
bool check[201][201];
queue<pair<int,int>> q;
queue<pair<int,int>> q2;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int s,a,b;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>n-1)
                continue;
            if(!check[dx][dy]){
                check[dx][dy] = 1;
                graph[dx][dy] = graph[x][y];
                q2.push(make_pair(dx,dy));
            }
        }
    }
}

void bfs2(){
    while(!q2.empty()){
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>n-1)
                continue;
            if(!check[dx][dy]){
                check[dx][dy] = 1;
                graph[dx][dy] = graph[x][y];
                q.push(make_pair(dx,dy));
            }
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    cin >> s >> a >> b;
    for(int t=1;t<=k;t++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==t){
                    q.push(make_pair(i,j));
                    check[i][j] = 1;
                }
            }
        }
    }
    for(int i=0;i<s;i++){
        if(i%2==0){
        bfs();
        }else{
            bfs2();
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << graph[a-1][b-1] << '\n';
}