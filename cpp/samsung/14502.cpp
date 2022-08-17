#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int n,m;
int graph[10][10];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<pair<int,int>> zero;
int zero_size = 0;
vector<pair<int,int>> picked;
vector<vector<pair<int,int>>> bfs_ready;
bool check[10][10];
int graph2[10][10];
vector<pair<int,int>> virus;

void bfs(int x,int y){
    check[x][y] =  true;
    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y +dir[i][1];
            if(check[dx][dy]) continue;
            if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0) continue;
            if(graph2[dx][dy] == 0){
                graph2[dx][dy] = 2;
                check[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
}

void copy_graph(int graph[10][10], int graph2[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            graph2[i][j] = graph[i][j];
        }
    }
}

void back_tracking(int index,int idx){
    if(index == 3){
        vector<pair<int,int>> temp;
        for(int i=0;i<picked.size();i++){
            temp.push_back({picked[i].first,picked[i].second});
        }
        bfs_ready.push_back(temp);
        return;
    }
    for(int i=idx;i<zero_size;i++){
        if(check[zero[i].first][zero[i].second])
            continue;
        check[zero[i].first][zero[i].second] = true;
        picked.push_back({zero[i].first,zero[i].second});
        back_tracking(index+1,i);
        picked.pop_back();
        check[zero[i].first][zero[i].second] = false;
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
            if(graph[i][j] == 0){
                zero.push_back({i,j});
            }else if(graph[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }
    zero_size = zero.size();
    back_tracking(0,0);
    int answer = 0;


    for(int i=0;i<bfs_ready.size();i++){
        copy_graph(graph,graph2);
        memset(check, false, sizeof(check));
        for(int j=0;j<bfs_ready[i].size();j++){
            int first = bfs_ready[i][j].first;
            int second = bfs_ready[i][j].second;
            graph2[first][second] = 1;
        }
        for(int j=0;j<virus.size();j++){
            bfs(virus[j].first,virus[j].second);
        }
        int expand = 0;

        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(graph2[j][k] == 0){
                    expand++;
                }
            }
        }

        answer = max(answer,expand);
        
    }

    cout << answer << '\n';

}