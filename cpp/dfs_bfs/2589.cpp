#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
char graph[51][51];
int graph_to_int[51][51];
bool check[51][51];
queue<pair<int,int>> q;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int x, int y){
    check[x][y] = 1;
    q.push(make_pair(x,y));
    int max_dis = 0;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(!check[dx][dy]&&graph_to_int[dx][dy]>0){
                check[dx][dy] = 1;
                graph_to_int[dx][dy] = graph_to_int[x][y] +1;
                q.push(make_pair(dx,dy));
                max_dis=max(max_dis,graph_to_int[dx][dy]);
            }
        }
    }
    return max_dis;
}

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]=='L'){
                graph_to_int[i][j] = 1;
            }else{
                graph_to_int[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check[i][j] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    int result = 0;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            graph[i][j] = str[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 'L'){
                graph_to_int[i][j] = 1;
            }else{
                graph_to_int[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph_to_int[i][j] == 1){
                result = max(result,bfs(i,j));
                reset();
            }
        }
    }
    cout << result - 1 << '\n';
}