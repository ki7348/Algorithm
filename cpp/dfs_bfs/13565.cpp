#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
int graph[1001][1001];
bool check[1001][1001];
queue<pair<int,int>> q;
vector<int> v;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int x,int y){
    check[x][y] = 1;
    q.push(make_pair(x,y));
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
                graph[dx][dy] = 1;
            }
        }         
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            graph[i][j] = str[j]-'0';
        }
    }
    for(int i=0;i<m;i++){
        if(graph[n-1][i]==0){
            v.push_back(i);
        }
    }
    for(int i=0;i<m;i++){
        if(graph[0][i]==0){
            bfs(0,i);
        }
    }
    for(int i=0;i<v.size();i++){
        if(graph[n-1][v[i]]==1){
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}